#pragma once

#include<semaphore.h>
#include<zookeeper/zookeeper.h>
#include<string>

// 封装zk客户端
class ZKClient
{
public:
    // zkclient启动连接zkserver
    ZKClient();
    ~ZKClient();
    void Start();
    // 在zkserver上根据指定的path创建znode节点
                        // 节点路径 节点数据 数据长度 state=0表示永久性节点
    void Create(const char* path, const char* data, int datalen, int state=0);
    // 根据参数指定的znode节点路径获取znode节点的值 
    std::string GetData(const char* path);
private:
    // zk的客户端句柄标识，通过这个句柄可以取操作zkserver
    zhandle_t *m_zhandle;
};