#include"friend.pb.h"
#include"mprpcapplication.h"
#include"mprpcprovider.h"
#include<iostream>
#include<vector>
class friendService : public fix::friendServiceRpc
{
    // 返回好友列表(本地方法)
    std::vector<std::string> getFriendList(uint32_t id)
    {
        std::cout<<"dong getfirendlist service!"<<std::endl;
        std::cout<<"userid is:"<<id<<std::endl;
        std::vector<std::string> friends;
        friends.push_back("peach");
        friends.push_back("jay");
        friends.push_back("fantasy");
        return friends;
    }   

    void getFriendList(::google::protobuf::RpcController* controller,
                       const ::fix::getFriendListRequest* request,
                       ::fix::getFriendListResponse* response,
                       ::google::protobuf::Closure* done)
    {
        // 将请求反序列化，得到userid(这是框架做好的)
        // 用userid作为参数调用本地方法获得好友列表vec
        uint32_t userid = request->id();
        std::vector<std::string> friendsVec = getFriendList(userid);
        // 遍历vec，将该userid的好友信息填入response对象
        for(auto fri: friendsVec)
        {
            // response由 resultcode和repeated friends组成
            response->add_friend_(fri);
        }
        response->mutable_resulecode()->set_error(0);
        response->mutable_resulecode()->set_errmsg("");
        // 完成操作，执行closure预设的回调操作，将response序列化通过网络发送出去
        done->Run();
    }
};

int main(int argc, char** argv)
{
    // 初始化框架   
    MprpcApplication::init(argc, argv);
    // 发布远程rpc方法
    RpcProvider provider;
    provider.NotifyService(new friendService());
    // 启动网络开始接受请求
    provider.Run();
    return 0;
}