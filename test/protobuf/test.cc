#include"test.pb.h"
#include<iostream>
#include<string>
using namespace std;
class userService : public fixbug::UserServiceRpc
{
    bool Login(string name, string pwd)
    {
        cout<<"name:"<<name<<endl;
        cout<<"pwd:"<<pwd<<endl;
    }

    virtual void Login(::google::protobuf::RpcController* controller,
                       const ::fixbug::LoginRequest* request,
                       ::fixbug::LoginResponse* response,
                       ::google::protobuf::Closure* done)
    {
        // 框架给业务上报了请求参数LoginRequest 应用程序获取相应数据做本地业务
        // protobuf的好处:直接将字节流反序列化成我们可用识别的LoginRequest对象，通过这个对象获得name和pwd
        string name = request->name();
        string pwd = request->pwd();
        // 做本地业务
        bool res = Login(name, pwd);                         //(ResultCode)
                                                            //errcode errmsg  success
        // 框架只是创建一个LoginResponse，我们需要把相应写入，包括错误码，错误消息，返回值
        response->set_success(res);
        fixbug::ResultCode *rc = response->mutable_result();
        rc->set_errmsg("");
        rc->set_errcode(0); 
    }

};

int main()
{
    
    return 0;
}

/*
fixbug::LoginRequest request;
    request.set_name("yang");
    request.set_pwd("aaa");
    // 序列化 serializeToString()
    std::string send_str;
    if(request.SerializePartialToString(&send_str))
    {
        std::cout<<send_str<<std::endl;
    }
    // 反序列化
    fixbug::LoginRequest request1;
    if(request1.ParseFromString(send_str))
    {
        std::cout<< request1.name() <<" " <<request1.pwd()<<std::endl;
    }
    fixbug::GetFriendListsResponse getFriendListR;
    fixbug::ResultCode * rc = getFriendListR.mutable_result();
    rc->set_errcode(0);
    fixbug::User *user1 = getFriendListR.add_friendlist();
    user1->set_id(0);
    user1->set_name("yang");
    user1->set_sex(fixbug::User::MAN);

    fixbug::User *user2 = getFriendListR.add_friendlist();
    user1->set_id(1);
    user1->set_name("yang1");
    user1->set_sex(fixbug::User::WOMAN);
    std::cout<<getFriendListR.friendlist_size()<<std::endl;
*/