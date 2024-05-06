#pragma once
#include"google/protobuf/service.h"
#include <muduo/net/TcpServer.h>
#include <muduo/net/EventLoop.h>
#include <muduo/net/InetAddress.h>
#include <muduo/net/TcpConnection.h>
#include <google/protobuf/descriptor.h>
#include <unordered_map>
#include <string>
// 框架提供的专门发布rpc服务的网络对象
// 启动网络服务并在上面发布rpc方法供别人远程调用，涉及高并发请求调用，这里使用muduo库
// RpcProvider
class RpcProvider
{
public:
    // 框架提供给外部使用，发布rpc方法的函数接口 NotifyService
    void NotifyService(google::protobuf::Service * service);
    // 框架应该是可以接收各种rpc服务，不依赖于具体的某一业务

    // 启动rpc服务节点，开始提供rpc远程网络调用服务
    void Run();
private:
    // 组合eventLoop
    muduo::net::EventLoop m_eventLoop;
    // service服务类型信息  
        // 保存服务对象指针
        // 保存服务方法(方法名，方法指针)
    struct serviceInfo_
    {
        google::protobuf::Service *service_;
        std::unordered_map<std::string, const google::protobuf::MethodDescriptor*> methodMap_; 
    };
    // 存储注册成功的服务对象名和服务类型信息
    std::unordered_map<std::string, serviceInfo_> serviceMap_;
    // 新的socket回调
    void onConnection(const muduo::net::TcpConnectionPtr&);
    // 如果muduo库发现有消息，建立用户的读写事件回调
    void onMessage(const muduo::net::TcpConnectionPtr&, muduo::net::Buffer*, muduo::Timestamp);
    // closure的回调操作，用户序列化rpc的相应和网络发送 
    void sendRpcResponse(const muduo::net::TcpConnectionPtr&conn, google::protobuf::Message* message);
};
    