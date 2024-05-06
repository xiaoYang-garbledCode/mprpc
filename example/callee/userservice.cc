#include"user.pb.h"
#include<iostream>
#include"mprpcapplication.h"
#include"mprpcprovider.h"
using namespace std;
/*
    UserService 原来是一个本地服务，提供两个进程的本地方法 Login Register
*/

// UserService 继承UserServiceRpc
class UserService : public fix::UserServiceRpc
{
public:
     // 本地实现Login方法 参数 name pwd  打印 bool
    bool Login(string name, string pwd)
    {
        cout<<"doing Login!"<<endl;
        cout<<"name:"<<name<<"pwd"<<pwd<<endl;
        return true;
    }
    // 本地实现register方法 参数 id name pwd 打印
    bool Register(int id, string name, string pwd)
    {
        cout<<"doing Register"<<endl;
        cout<<"id:"<< id <<"name:"<< name <<"pwd"<< pwd <<endl;
        return true;
    }
    // 重写 UserServiceRpc提供的虚函数Login
    void Login(::google::protobuf::RpcController* controller,
                       const ::fix::LoginRequest* request,
                       ::fix::LoginResponse* response,
            ::google::protobuf::Closure* done)
    {
        // 框架给业务上报了请求参数LoginRequest 应用程序获取相应数据做本地业务
        // protobuf的好处:直接将字节流反序列化成我们可用识别的LoginRequest对象，通过这个对象获得name和pwd
        string name = request->name();
        string pwd = request->pwd();
        // 做本地业务
        bool res = Login(name, pwd);                         //(ResultCode)
                                                            //errcode errmsg  success
        // 框架只是创建一个LoginResponse，我们需要把相应写入，包括错误码，错误消息，返回值
        response->set_sucess(res);
        fix::ResultCode *rc = response->mutable_result();
        rc->set_errmsg("");
        rc->set_errcode(0);
        // 执行回调操作，执行相应对象数据的序列化和网络发送(都是框架完成)
        done->Run();
    }
    // 重写 UserServiceRpc提供的虚函数Register
    void Register(::google::protobuf::RpcController* controller,
                       const ::fix::RegisterRequest* request,
                       ::fix::RegisterResponse* response,
                       ::google::protobuf::Closure* done)
    {
        uint32_t id = request->id();
        std::string name = request->name();
        std::string pwd = request->pwd();
        bool result = Register(id,name,pwd);
        
        response->set_sucess(result);
        fix::ResultCode* rc = response->mutable_result();
        rc->set_errcode(0);
        rc->set_errmsg("");
        done->Run();
    }
};
   
int main(int argc, char** argv)
{
    //调用框架的初始化操作
    MprpcApplication::init(argc, argv);
    // 利用RpcProvider进行notifyService (发布服务) 可以调用多次生成多个远程rpc服务
    RpcProvider provider;
    // 启动一个rpc服务发布点
    provider.NotifyService(new UserService());

    // run以后进程进入阻塞状态，等待远程rpc调用请求
    provider.Run();
    return 0;
}