#set(SRC_LIST userservice.cc ../user.pb.cc)
set(SRC_LIST friendservice.cc ../friend.pb.cc)
#aux_source_directory(. SRC_LIST)
# 由SRC_LIST编译连接生成可执行文件
add_executable(provider ${SRC_LIST})

# 需要链接的库
target_link_libraries(provider mprpc protobuf)