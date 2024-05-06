#include"friend.pb.h"
#include"mprpcapplication.h"
#include<vector>
#include<string>
#include"logger.h"

int main(int argc, char** argv)
{   
    LOG_INFO("KKKK");
    // 初始化框架
    MprpcApplication::init(argc, argv);
    
    // 通过stub类调用远程发布的rpc方法
    fix::friendServiceRpc_Stub stub(new MprpcChannel());

    // 构造rpc请求参数并填入，构造rpc response
    fix::getFriendListRequest request;
    fix::getFriendListResponse response;
    MprpcController mycontroller;
    request.set_id(777);
    // stub同步调用方法
    stub.getFriendList(nullptr, &request, &response, nullptr);
   
    if(mycontroller.Failed()) // rpc调用过程中出现错误
    {
        std::cout<< mycontroller.ErrorText()<<std::endl;
    }
    else
    {
         // 从response获取方法执行返回值
        if(response.resulecode().error() == 0)
        {
            // 方法调用成功 反序列化数据，获得好友列表信息,框架完成的
            // 遍历response的好友列表打印好友信息
            int size = response.friend__size();
            for(int i=0; i<size;++i)
            {
                std::cout<< "friend name:" << response.friend_(i)<<std::endl;
            }
        }
        else{
            std::cout<< "远程rpc调用失败"<<std::endl;
        }
    }
    return 0;
}