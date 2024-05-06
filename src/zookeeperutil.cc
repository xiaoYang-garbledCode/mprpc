#include"zookeeperutil.h"
#include"mprpcapplication.h"
void global_watcher(zhandle_t * zh, int type,
                int state, const char* path, void *watcherCtx)
{
    if(type == ZOO_SESSION_EVENT) // 回调消息类型 是和会话相关的消息类型
    {
        if(state == ZOO_CONNECTED_STATE) // zkclient 和zkserver连接成功才建立会话
        {
            sem_t *sem = (sem_t*)zoo_get_context(zh);// 指定的句柄获取信号量
            sem_post(sem);  //信号量资源加1
        }
    }
}
ZKClient::ZKClient()
    :m_zhandle(nullptr)
{
}
ZKClient::~ZKClient()
{
    if(m_zhandle!=nullptr)
    {
        // 关闭句柄，释放资源相当于MySQL_Conn
        zookeeper_close(m_zhandle);
    }
}
// 连接zkserver 2181端口
void ZKClient::Start()
{
    // 获取配置文件zookeeper的ip和端口
    std::string host = MprpcApplication::getInstance().getConfig().Load("zookeeperip");
    std::string port = MprpcApplication::getInstance().getConfig().Load("zookeeperport");
    // zookeeper要求ip和端口的格式位： host + ":" + port
    std::string connstr = host + ":" + port;
    /*
        zookeeper_mt 表示多线程版本
        zookeeper的API客户端程序提供了三个线程
        API调用线程 当前线程
        网络I/O线程 poll专门负责网络连接
        watcher回调线程，当客户端收到zkserver的响应，
        服务器再次调用pthread_create，产生watcher回调线程
    */
    m_zhandle = zookeeper_init(connstr.c_str(), global_watcher, 30000, nullptr,nullptr,0);
   // 返回的就是句柄，会话的创建是异步的，并不是返回成功了就表示连接成功的
   // 等回调函数真正接收到zkserver响应进行回调

   // 表示发起连接的动作没有产生，传的参数有问题
    if(nullptr == m_zhandle)
    {
        std::cout<< "zookeeper_init error!" << std::endl;
        exit(EXIT_FAILURE);
    }
   // 创建信号量
    sem_t sem;
   // 初始化信号量
    sem_init(&sem,0,0);
   // 创建句柄资源成功后，在句柄资源上设置上下文，添加额外的信息
    zoo_set_context(m_zhandle, &sem);
   // 等待，因为初始的信号量是0，阻塞着等zkserver响应(回调)，等资源有了才往下走
    sem_wait(&sem);
   // global_watcher执行成功，连接成功
    std::cout<<"zookeeper_init success"<<std::endl;
}
// 在zkserver上根据指定的path创建znode节点
                    // 节点路径 节点数据 数据长度 state=0表示永久性节点
void ZKClient::Create(const char* path, const char* data, int datalen, int state)
{
    char path_buffer[128];
    int bufferlen = sizeof(path_buffer);
    int flag;
    // 先判断path表示的znode节点是否存在，如果存在就不再重复创建 zoo_exists
                                                    // m_zhandle path 
    flag = zoo_exists(m_zhandle, path, 0,0);
    // ZNONODE 表示path的znode节点不存在
        // 创建指定path的znode节点 zoo_create
                            // 句柄，路径，数据，数据长度，flag默认创建永久性
        // flag 是ZOK表示创建成功
    if(flag == ZNONODE)
    {
        flag = zoo_create(m_zhandle,path, data, datalen, 
                    &ZOO_OPEN_ACL_UNSAFE, state, path_buffer,bufferlen);
        if(flag == ZOK)
        {
            std::cout<<"znode create success ... path" << path<<std::endl;
        }
        else
        {
            std::cout<<"flag:"<<flag<<std::endl;
            std::cout<<"znode create error... path"<< path << std::endl;
            exit(EXIT_FAILURE);
        }
    }
}
// 根据参数指定的znode节点路径获取znode节点的值 
std::string ZKClient::GetData(const char* path)
{
    char buf[64];
    int buffer_len = sizeof(buf);
    // zoo_get(zhandle_t *zh, const char *path, int watch, char *buffer,   
    //                int* buffer_len, struct Stat *stat)
    int flag = zoo_get(m_zhandle, path, 0, buf, &buffer_len, nullptr);
    if(flag !=ZOK)
    {
        std::cout<<"get znode error... path:"<<path<<std::endl;
        return"";
    }
    else{
        return buf;
    }
}