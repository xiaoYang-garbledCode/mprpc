#include<iostream>
#include"user.pb.h"
#include"mprpcapplication.h"

int main(int argc, char**argv)
{
    // 整个程序启动以后，使用mprpc框架来享受rpc服务调用，需要先调用框架的初始化函数(只初始化一次)
    MprpcApplication::init(argc, argv);
    // 演示调用远程发布的rpc方法login
    fix::UserServiceRpc_Stub stub(new MprpcChannel());

    // rpc方法的请求参数
    fix::LoginRequest request;
    fix::RegisterRequest request1;
    request.set_name("yang");
    request.set_pwd("123");

    request1.set_id(777);
    request1.set_name("peach");
    request1.set_pwd("ppp");
    // 定义rpc方法的响应
    fix::LoginResponse response;
    fix::RegisterResponse response1;
    // 发起rpc方法的调用，这是同步的rpc调用过程 MprpcChannel::callmethod，
    // 数据序列化然后发送，等待远程rpc给我响应这个执行的方法结果
    stub.Login(nullptr, &request, &response, nullptr);
    stub.Register(nullptr, &request1, &response1, nullptr);
    // RpcChannel->rpcchannel::callmethod 集中起来做所有rpc方法调用的参数序列化和网络发送
    // 程序跑到这说明一次rpc调用完成，读调用结果   
    if(response.result().errcode() == 0)
    {
        std::cout<< "rpc login response success："<< response.sucess()<<std::endl;
    }
    else
    {
        std::cout<< "rpc login response error："<< response.result().errmsg();
    }
    if(response1.result().errcode() == 0)
    {
        std::cout<< "rpc register response success："<< response1.sucess()<<std::endl;
    }
    else
    {
        std::cout<< "rpc login response error："<< response1.result().errmsg();
    }
    return 0;
}