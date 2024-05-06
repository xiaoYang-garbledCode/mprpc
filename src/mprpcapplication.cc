#include"mprpcapplication.h"
#include<iostream>
#include<unistd.h>
MprpcConfig MprpcApplication::mConfig_;
// showArgsHelp 提示格式必须是 command -i <configfile>
void showArgsHelp()
{
    std::cout<<"format: command -i <configfile>" << std::endl;
}
MprpcApplication& MprpcApplication::getInstance()
{
    static MprpcApplication app;
    return app;
}

// 获取config对象
MprpcConfig& MprpcApplication::getConfig()
{
    return mConfig_;
}

void MprpcApplication::init(int argc, char** argv)
{
    // 如果参数argc<2 这说明没有传入任何参数 exit;
    if(argc < 2)
    {
        showArgsHelp();
        exit(EXIT_FAILURE);
    }
    // 利用getopt函数
    int c =0;
    std::string config_file;
    while((c = getopt(argc,argv, "i:")) !=-1)
    {
        switch(c)
        {
        case 'i':
            config_file = optarg;
            break;
        case '?':
            showArgsHelp();
            exit(EXIT_FAILURE);
        case ':':
            showArgsHelp();
            exit(EXIT_FAILURE);
        default:
            break;
        }
    }
    // 开始加载配置文件 
    mConfig_.loadConfigFile(config_file.c_str());

    std::cout<<"rpcserverip:"<<mConfig_.Load("mprpcserverip")<<std::endl;
    std::cout<<"rpcserverport:"<<mConfig_.Load("mprpcserverport")<<std::endl;
    std::cout<<"zookeeperip:"<<mConfig_.Load("zookeeperip")<<std::endl;
    std::cout<<"zookeeperport:"<<mConfig_.Load("zookeeperport")<<std::endl;
}