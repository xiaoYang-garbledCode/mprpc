#include"mprpcprovider.h"
#include"mprpcapplication.h"
#include"rpcheader.pb.h"
#include<string>
#include"logger.h"
#include"zookeeperutil.h"
using namespace std;
/*
    service_name => 描述service
                        =》 对于service*
                        =》 对于多个method方法对象
*/
// 框架提供给外部使用，发布rpc方法的函数接口 NotifyService
void RpcProvider::NotifyService(google::protobuf::Service * service)
{
    // 服务信息结构体 包括服务对象指针和它所有的方法
    serviceInfo_ service_info;
    service_info.service_ = service;
    // 获取了服务对象的描述信息
    const google::protobuf::ServiceDescriptor *pserviceDesc = service->GetDescriptor();
    // 获取服务的名字
    std::string service_name = pserviceDesc->name();
    // 获取服务对象service的方法数量
    int method_num = pserviceDesc->method_count();
    // 在for里遍历
        // 获取服务对象指定下标的方法描述 由服务对象描述信息-》method(i)
        // 将方法名和方法描述指针保存起来
    for(int i=0; i< method_num;i++)
    {
        const google::protobuf::MethodDescriptor* pmethodDesc = pserviceDesc->method(i);
        string method_name = pmethodDesc->name();
        service_info.methodMap_.insert({method_name, pmethodDesc});

        //打印方法名
        // std::cout<<"method_name:"<<method_name<<std::endl;
        LOG_INFO("method_name:%s", method_name.c_str());
    }
    // 在把这个服务对象名和它的所有方法存起来
    serviceMap_.insert({service_name, service_info});
}
    


// 新的socket回调
void RpcProvider::onConnection(const muduo::net::TcpConnectionPtr&conn)
{
    // 连接断开是关闭文件描述符 conn->shutdown()
    if(!conn->connected())
    {
        conn->shutdown();
    }
}


/*
    在框架内部，rpcprovider和rpcconsumer协商通信所用的protobuf数据类型
    包含：service_name method_name args
        头部 服务名     方法名 参数
    对应：16UserService Login peach yang123
    如何区分service_name method_name args  tcp传输存在粘包问题(需要记录参数长度)
    在protobuf里设计message来表示头部信息
    设计消息头
    消息头部长度        (服务名和方法名)   参数
    header_size(4字节)+ header_str +    args_str
    (头部的最大长度为四字节)
    统一：一开始读4个字节作为数据头的长度(除取参数之外的所有数据--服务名、方法名、参数长度)
*/

// 如果muduo库发现有消息，建立用户的读写事件回调
void RpcProvider::onMessage(const muduo::net::TcpConnectionPtr& conn, muduo::net::Buffer* buf, 
                            muduo::Timestamp)
{
    // 网络上接收远程rpc调用请求的字符流，包含RPC方法名Login和参数args_size
    // 将字符流以字符串的方式接收
    std::string recv_buf = buf->retrieveAllAsString();
    // 从字符流中读取四个字节内容  string.copy(); 将4字节内容拷贝到uint32_t中，表示数据头长度
    uint32_t head_size = 0;
    recv_buf.copy((char*)&head_size,4,0);
    // 字符串切割除 头部信息 与参数信息
    std::string rpc_head_str = recv_buf.substr(4, head_size);
    mprpc::RpcHeader rpcHeader;
    std::string service_name;
    std::string method_name;
    uint32_t args_size;
    // 将头部信息字符串反序列化，得到服务名，方法名，参数长度信息(args_size)
        // 反序列化失败，打印parse error 直接return
    if(rpcHeader.ParseFromString(rpc_head_str))
    {
        service_name = rpcHeader.service_name();
        method_name = rpcHeader.method_name();
        args_size = rpcHeader.args_size();
    }
    else{
        std::cout<<"parse rpcHeader fail!"<<std::endl;
        return;
    }

    // 根据参数长度信息获得参数信息
                //  头部长度      头部信息     
    std::string args_str = recv_buf.substr(4 + head_size, args_size); 
    // 打印所有信息 header_size rpc_head_str service_name method_name args_size args_str
    std::cout<<"=======获取的所有参数信息======="<<std::endl;
    std::cout<<"header_size:"<<head_size<<std::endl;
    std::cout<<"rpc_head_str:"<<rpc_head_str<<std::endl;
    std::cout<<"service_name:"<<service_name<<std::endl;
    std::cout<<"method_name:"<<method_name<<std::endl;
    std::cout<<"args_size:"<<args_size<<std::endl;
    std::cout<<"args_str:"<<args_str<<std::endl;

    serviceInfo_ serviceInfo; // 服务信息结构体
    google::protobuf::Service *pservice;
    const google::protobuf::MethodDescriptor* pmethod;
    // 获取service对象和method(methoddescriptor)对象
    auto it = serviceMap_.find(service_name);
    if(it!= serviceMap_.end())
    {   
        serviceInfo = it->second;
        pservice = serviceInfo.service_;
    }
    else{
        std::cout<<"找不到该服务"<<std::endl;
        return;
    }
    auto it1 = serviceInfo.methodMap_.find(method_name);
    if(it1 != serviceInfo.methodMap_.end())
    {
        pmethod = it1->second;
    } else{
        std::cout<<"找不到该方法"<<std::endl;
        return;
    }
    // 生成rpc方法调用请求request参数  service->getrequestprototype 在框架以抽象的方式生成，new生成新对象传给userservice
    google::protobuf::Message* request = pservice->GetRequestPrototype(pmethod).New();
    // request解析参数信息(args_str) 
        // 解析失败打印信息 return
    if(!request->ParseFromString(args_str))
    {
        std::cout<<"args_str解析失败"<<std::endl;
    }
    // 生成rpc方法相应response参数
    google::protobuf::Message* response = pservice->GetResponsePrototype(pmethod).New();

    // callMethod需要closure参数
    // 给下面的method方法的调用绑定一个closure的回调函数
    google::protobuf::Closure* done = google::protobuf::NewCallback
                            <RpcProvider,const muduo::net::TcpConnectionPtr&, 
                            google::protobuf::Message*>
                            (this, &RpcProvider::sendRpcResponse,conn,response); 
    // 在框架上根据远端rpc请求调用调取rpc节点上发布的方法
    // 做完本地服务，根据结果写好response，框架再发送给调用方
    // 等价于 new UserService().Login(controller, request, response, done)
    pservice->CallMethod(pmethod, nullptr, request, response, done);
}

// closure的回调操作，用于序列化rpc相应和网络发送
void RpcProvider::sendRpcResponse(const muduo::net::TcpConnectionPtr&conn, 
                            google::protobuf::Message* response)
{
    // 对response 进行序列化
        // 序列化成功后，通过网络把rpc方法的执行结果发送给rpc的调用方
    std::string result;
    if(response->SerializePartialToString(&result))
    {
        conn->send(result);
    }
    else
    {
        std::cout<<"response 序列化失败"<<std::endl;
    }
    // 关闭连接(模拟http的短连接服务，由provider主动断开连接，给更多的rpc调用方提供服务)
    conn->shutdown();
}

// 启动rpc服务节点，开始提供rpc远程网络调用服务
void RpcProvider::Run()
{
    // 读取配置文件信息 ip port
    string ip = MprpcApplication::getInstance().getConfig().Load("mprpcserverip");
    unsigned int port = atoi(MprpcApplication::getInstance().getConfig().Load("mprpcserverport").c_str());
    // 用inetAddress 将ip和port组成地址
    muduo::net::InetAddress address(ip,port);
    // 创建tcpserver对象 eventloop inetaddress 名字
    muduo::net::TcpServer server(&m_eventLoop, address, "mprpcserver");
    // 绑定连接和读写回调方法，muduo库的好处：分离了网络代码和业务代码
    server.setConnectionCallback(std::bind(&RpcProvider::onConnection,this,std::placeholders::_1));
    server.setMessageCallback(std::bind(&RpcProvider::onMessage,this,std::placeholders::_1,
                        std::placeholders::_2,std::placeholders::_3));
    // 设置muduo库的线程数量
    server.setThreadNum(4);

    // 把当前rpc节点上要发布的服务全部注册到zk上，让rpc client可以从zk上发现服务
    // 连接zkserver
    ZKClient zkCli;
    zkCli.Start();
    // service_name为永久性节点 method_name为临时性节点
    // 遍历map，将填写service_path method_path 并创建相应的node
    for(auto &sp :serviceMap_)
    {
        std::string service_path = "/" + sp.first;
        char service_data[128]={0};
        zkCli.Create(service_path.c_str(), nullptr,0);
        for(auto &mp : sp.second.methodMap_)
        {
            
        }
    }

    // rpc服务准备启动，打印 rpcprovider start service at ip port
    std::cout<<"rpcprovider start service at ip:"<<ip<<"port:"<<port<<std::endl;
    // 启动网络服务 start  loop
    server.start();
    // loop相当于启动epoll_wait 阻塞等待远程连接
    m_eventLoop.loop();
}

