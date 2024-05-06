cmake_minimum_required(VERSION 3.0)
project(rpc)

# 遍历选项可调式
set(CMAKE_BUILD_TYPE "Debug")

# 头文件搜索路径
include_directories(${PROJECT_SOURCE_DIR}/src/include)
include_directories(${PROJECT_SOURCE_DIR}/example)
# 项目库文件搜索路径
link_libraries(${PROJECT_SOURCE_DIR}/lib)
# 生成可执行文件路径
set(EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/bin)
# 生成动态或静态库路径
set(LIBRARY_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/lib)
# 子目录
add_subdirectory(src)
add_subdirectory(example)