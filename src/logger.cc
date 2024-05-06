#include"logger.h"
#include<thread>
#include<iostream>
#include<time.h>
// 获取日志单例
Logger& Logger::getInstance()
{
    static Logger logger;
    return logger;
}
Logger::Logger()
{
     // 启动专门写日志线程    lambda表达式等于函数对象
    std::thread writeTask([&]()->void{
        // 写日志线程函数一直不断运行for
        for(;;)
        {
            // 获取当前的日期，之后取日志信息，写入相应的日志文件中(a+方式) 追加的方式没有就创建
            // time获取当前的时间，按秒算的，1970年到现在
            time_t curday = time(nullptr);
            //  localtime //返回tm结构的指针
            struct tm* curday_st = localtime(&curday);
            // 以1970-3-19-log.txt来命名日志文件 sprintf
            char time_seq[128]={0};
            sprintf(time_seq, "%d-%d-%d-log.txt",
                    curday_st->tm_year + 1900, curday_st->tm_mon + 1,
                    curday_st->tm_mday);
            // 打开日志文件
                // 打开失败，打印失败信息
            FILE* pf = fopen(time_seq,"a+");
            if(pf == nullptr)
            {
                std::cout<<"打开日志文件失败,文件名为:"<<time_seq<<std::endl;
                exit(EXIT_FAILURE);
            }
            // 从日志缓冲队列中取日志信息
            std::string logInfo = lockqueue_.Pop();
            // 并将当前的时间(时分秒)，以及信息类型logLevel_，信息插入到日志信息的头部
            char curtime[128] = {0};
            sprintf(curtime, "%d:%d:%d=>[%s]",
                    curday_st->tm_hour,  curday_st->tm_min, curday_st->tm_sec
                    ,logLevel_ == LogLevel::INFO ? "info":"error");
            logInfo.insert(0,curtime);
            // 在信息尾部插入"\n"
            logInfo.append("\n");
            // 将信息写入文件 fputs
            // 关闭文件
            fputs(logInfo.c_str(), pf);
            fclose(pf);
        }
    });
    writeTask.detach();
}
// 设置日志级别
void Logger::setLogLevel(LogLevel loglevel)
{
    logLevel_ = loglevel;
}
// 写日志
void Logger::writeLog(std::string msg)
{ 
   lockqueue_.Push(msg);
}