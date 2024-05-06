#pragma once
#include"mprpcconfig.h"
#include"mprpcchannel.h"
#include"mprpccontroller.h"
// mprpc框架的基础类，负责框架的一些初始化操作
// MprpcApplication
class MprpcApplication
{
public:
    static MprpcApplication& getInstance();// 单例模式 //定义唯一的对象实例。静态局部对象，是线程安全的。
    static void init(int argc, char** argv);// init初始化方法 argc argv
    MprpcConfig& getConfig();
private:
    static MprpcConfig mConfig_; // 静态成员变量要在类外初始化
    MprpcApplication(){} // 构造函数私有化
    // 删除对应的拷贝构造和赋值构造
    MprpcApplication(const MprpcApplication& mprpc) = delete;
    MprpcApplication& operator=(const MprpcApplication& mprpc) = delete;
};

    