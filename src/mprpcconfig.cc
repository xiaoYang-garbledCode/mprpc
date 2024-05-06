#include"mprpcconfig.h"
#include<string>
#include<iostream>
// 负责解析配置文件
void MprpcConfig::loadConfigFile(const char* config_file)
{
    // 打开文件
    FILE* pf = fopen(config_file, "r");
    // 如果文件为空，报错 exit退出
    if(pf == nullptr)
    {
        std::cout << config_file << " is note exist!" << std::endl;
        exit(EXIT_FAILURE);
    }
    // 遍历文件内容while(!feof)
    while(!feof(pf))
    {
        // 用fget从文件中一个循环读取一行,最多读取511个字符或者读到'\n'停
        char buf[512] ={0};
        fgets(buf, 512, pf);
        // 将字符串前部的多余空格去除 Trim
        std::string read_buf(buf);
        Trim(read_buf);
        // 判断注释'#'，如果是，继续读下一行
        if(read_buf[0] == '#' | read_buf.empty())
        {
            continue;
        }
        // 解析配置项':'
            // 配置项不合法，继续下一行
        int idx = read_buf.find("=");
        if(idx==-1)
        {
            continue;
        }
        // 分别解析出key、value
        std::string key, value;
        key = read_buf.substr(0,idx);
        Trim(key);
        // rpcserverip = 127.0.0.1\n
        int endidx = read_buf.find("\n");
        value = read_buf.substr(idx+1, endidx-idx-1);
        // 分别去除它们的前部多余空格
        Trim(value);
        // 并加key、value加入m_configMap
        m_configMap.insert({key,value});
    }
   
}
// 查询配置项信息
std::string MprpcConfig::Load(const std::string &key)
{
    auto it = m_configMap.find(key);
    if(it!=m_configMap.end())
    {
        return it->second;
    }
    return "";
}
// 去掉字符串前后的空格
void MprpcConfig::Trim(std::string &src_buf)
{
    // 找第一个位置不为空的字符的下标
    size_t first = src_buf.find_first_not_of(" ");
    if(first==std::string::npos)
    {
        //所有全部为空格 
        src_buf="";
        return;
    }
    // 找到最后一个不为空的字符
    size_t end = src_buf.find_last_not_of(" ");
    src_buf = src_buf.substr(first, end-first+1); 
}