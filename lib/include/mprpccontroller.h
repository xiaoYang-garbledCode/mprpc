#pragma once
#include<google/protobuf/service.h>
#include<string>

class MprpcController : public google::protobuf::RpcController
{
public:
    MprpcController();
    //重置方法
    void Reset();
    //判断是否错误
    bool Failed() const;
    //返回错误信息
    std::string ErrorText() const;
    //设置错误状态
    void SetFailed(const std::string& reason);
    //========未实现的功能
    void StartCancel();
    bool IsCanceled() const;
    void NotifyOnCancel(google::protobuf::Closure* callback);
private:
    bool m_failed; //rpc方法执行过程中的状态
    std::string m_errText; //rpc方法执行过程中的错误信息
};