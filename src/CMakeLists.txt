# 用SRC_LIST表示当前路径下的所有文件
# aux_source_directory(. SRC_LIST)
set(
    SRC_LIST
    mprpcapplication.cc
    mprpcconfig.cc
    mprpcprovider.cc
    mprpcchannel.cc
    rpcheader.pb.cc
    mprpccontroller.cc
    logger.cc
    zookeeperutil.cc
)
# 添加一个从source列表列出的文件构建而来的目标名为name的库
add_library(mprpc ${SRC_LIST})

target_link_libraries(mprpc muduo_net muduo_base pthread zookeeper_mt)