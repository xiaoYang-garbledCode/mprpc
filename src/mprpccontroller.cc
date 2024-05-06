#include"mprpccontroller.h"
MprpcController::MprpcController()
    :m_failed(false) // 初始化，一开始认为是正确的
    ,m_errText("")
{}
//重置方法
void MprpcController::Reset()
{
    m_failed = false;
    m_errText = "";
}
//判断是否错误
bool MprpcController::Failed() const
{
    return m_failed;
}
//返回错误信息
std::string MprpcController::ErrorText() const
{
    return m_errText;
}
//设置错误状态
void MprpcController::SetFailed(const std::string& reason)
{
    m_failed = true;
    m_errText = reason;
}
void MprpcController::StartCancel()
{}
bool MprpcController::IsCanceled() const
{
    return false;
}
void MprpcController::NotifyOnCancel(google::protobuf::Closure* callback)
{}