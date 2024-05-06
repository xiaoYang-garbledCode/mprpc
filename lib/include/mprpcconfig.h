#pragma once
#include<string>
#include<unordered_map>
// 框架读取配置文件
class MprpcConfig
{
public:
    // 负责解析配置文件
    void loadConfigFile(const char* config_file);
    // 查询配置项信息
    std::string Load(const std::string &key);
    
private:
    // 配置信息map(string,string)
    std::unordered_map<std::string,std::string> m_configMap;
    // 去掉字符串前后的空格
    void Trim(std::string &src_buf);
};

    