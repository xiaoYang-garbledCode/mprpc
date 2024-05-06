#include"mprpcchannel.h"
#include"rpcheader.pb.h"
#include"mprpcapplication.h"
#include"mprpccontroller.h"
#include<string>
#include<sys/socket.h>
#include<sys/types.h>
#include<arpa/inet.h>
#include<netinet/in.h>
#include<unistd.h>
#include<errno.h>
// 所有提供stub代理对象调用的rpc方法都走到这里，统一做rpc方法调用的数据序列化和网络发送
void MprpcChannel::CallMethod(const google::protobuf::MethodDescriptor* method,
                        google::protobuf::RpcController* controller, 
                        const google::protobuf::Message* request,
                        google::protobuf::Message* response, 
                        google::protobuf::Closure* done)
{
    // 这个方法是属于哪个service的，通过方法获得servicedescriptor
    const google::protobuf::ServiceDescriptor* pserverDesc = method->service();
    // 获得servicename 和 methodname
    std::string service_name = pserverDesc->name();
    std::string method_name = method->name();
    // 获取参数序列化字符串长度 args_size
    uint32_t args_size =0;
    std::string args_str;
    // 序列化成功 
    if(request->SerializePartialToString(&args_str))
    {
        args_size = args_str.size();
    }
    else
    {
        // 失败打印相关信息
        controller->SetFailed("序列化request失败");
        return;
    }
    // 定义rpc的请求rpcheader
    // 将servicename methodname args_size 填入
    mprpc::RpcHeader rpc_header;
    // 将rpcheader序列化，header_size等于rpcheader序列化后的长度
    rpc_header.set_service_name(service_name);
    rpc_header.set_method_name(method_name);
    rpc_header.set_args_size(args_size);
    uint32_t header_size = 0;
    std::string rpc_header_str;
    if(rpc_header.SerializePartialToString(&rpc_header_str))
    {
        header_size = rpc_header_str.size();
    }
    else{
        // 序列化失败打印相关信息
        controller->SetFailed("序列化rpc_header_str 失败");
    }
    // 组织发送rpc请求的字符串send_rpc_str
    // 先在头部插入header_size,共占从头开始的四个字节
    // 在send_rpc_str继续插入 header_str args_str
    std::string send_rpc_std;
    send_rpc_std.insert(0,std::string((char*)&header_size,4));
    send_rpc_std += rpc_header_str; //rpcheader
    send_rpc_std += args_str; // args

    // 打印调试信息
    std::cout <<"===================================" <<std::endl;
    std::cout<< "header_size:" << header_size << std::endl;
    std::cout<< "rpc_header_str:" << rpc_header_str << std::endl;
    std::cout<< "service_name:" << service_name << std::endl;
    std::cout<< "method_name:" << method_name << std::endl;
    std::cout<< "args_str:" << args_str << std::endl;
    std::cout<< "args_size:" << args_size << std::endl;
    std::cout <<"===================================" <<std::endl;
    // 因为是客户端(消费者)，不需要高并发，只需使用tcp编程，完成rpc方法的远程调用
    int clientfd = socket(AF_INET, SOCK_STREAM,0); 
    // 创建链接套接字
        // 套接字创建失败
        // return
    if(clientfd ==-1)
    {
        char errtxt[512] = {0};
        sprintf(errtxt, "create socket error! errno%d", errno);
        controller->SetFailed(errtxt);
        return;
    }
    // 读取配置文件的rpcserver信息
    std::string ip = MprpcApplication::getInstance().getConfig().Load("mprpcserverip");
    uint16_t port = atoi(MprpcApplication::getInstance().getConfig().Load("mprpcserverport").c_str());
    // 将rpcserver信息填入 sockaddr_in server_addr 中   sin_family  port ip
    struct sockaddr_in server_addr;
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(port);
    server_addr.sin_addr.s_addr = inet_addr(ip.c_str());
    // 发起连接
        // 连接失败 关闭套接字 return
    if(-1 == connect(clientfd, (struct sockaddr*)&server_addr,sizeof(server_addr)))
    {
        close(clientfd);
        char errtxt[512] = {0};
        sprintf(errtxt, "connect error! error%d",errno);
        controller->SetFailed(errtxt);
        return;
    }
    // 连接成功，发送rpc请求，序列化的数据
        // 发送失败 同理
    if(-1 == send(clientfd, send_rpc_std.c_str(),send_rpc_std.size(),0))
    {
        close(clientfd);
        char errtxt[512] = {0};
        sprintf(errtxt, "send error! error%d",errno);
        controller->SetFailed(errtxt);
        return;
    }
    // 接收rpc请求的响应 recv_buf
    char recv_buf[1024] = {0};
    int recv_size = 0;
    if(-1 ==(recv_size = recv(clientfd, &recv_buf, 1024,0)))
    {
        close(clientfd);
        char errtxt[512] = {0};
        sprintf(errtxt, "recv error! error%d",errno);
        controller->SetFailed(errtxt);
        return;
    }
    // 反序列化响应数据，填入response中
        // 失败 同理
    if(!response->ParseFromArray(recv_buf,recv_size))
    {
        close(clientfd);
        char errtxt[512] = {0};
        sprintf(errtxt, "ParseFromArray error! error%d",errno);
        controller->SetFailed(errtxt);
        return;
    }
    // 关闭套接字描述符
    close(clientfd);
}