#pragma once
#include"lockqueue.h"
#include<string>
/*
    定义宏 LOG_INFO("XXX %d %s", 20, "xxx")
    可变参，让用户更轻松的使用logger
    snprintf，缓冲区，缓冲区长度，写的格式化字符串，##__VA_ARGS__
    代表可变参的参数列表，填到缓冲区中，然后logger.Log(c)
*/
#define LOG_INFO(logmsgformat, ...)\
    do\
    { \
        Logger &log = Logger::getInstance();\
        log.setLogLevel(INFO);\             
        char buf[1024] ={0} ;\                 
        snprintf(buf,1024,logmsgformat, ##__VA_ARGS__);\
        log.writeLog(buf);\
    }while(0)\

#define LOG_ERR(logmsgformat, ...)\
    do\
    {\
        Logger& log = Logger::getInstance();\
        log.setLogLevel(ERROR);\
        char buf[1024]={0};\
        snprintf(buf, 1024, logmsgformat, ##__VA__ARGS__);\
    }while(0)\

// 定义日志级别   普通信息，错误信息
enum LogLevel
{
    INFO, //普通日志
    ERROR, //错误日志
};

// mprpc框架提供的日志系统
class Logger
{
public:
    // 获取日志单例
    static Logger& getInstance();
    // 设置日志级别
    void setLogLevel(LogLevel);
    // 写日志
    void writeLog(std::string msg);
private:
    Logger();//构造函数私有化
    int logLevel_;// 记录日志级别
    lockQueue<std::string> lockqueue_;// 日志缓冲队列

    Logger(const Logger&)= delete;// 删除拷贝和赋值构造
    Logger(Logger&&) = delete;
};
    
    