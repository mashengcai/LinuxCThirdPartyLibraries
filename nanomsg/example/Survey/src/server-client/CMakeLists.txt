cmake_minimum_required(VERSION  3.16.3)

#${PROJECT_NAME}
project(survey)

#######################################################################
set(CMAKE_CXX_STANDARD 11)
#set(CMAKE_CXX_FLAGS  "${CMAKE_CXX_FLAGS}   -lcrypto")
#添加对c++11的支持
#set(CMAKE_CXX_FLAGS  "-std=c++11" )
#set(CMAKE_CXX_FLAGS  "${CMAKE_CXX_FLAGS} -std=c++11")
#set(CMAKE_CXX_FLAGS  -lcrypto  )

#######################################################################
#gdb 调试选项[begine]
 #定义编译类型
SET(CMAKE_BUILD_TYPE "Debug")
#定义Debug编译参数
SET(CMAKE_CXX_FLAGS_DEBUG  "$ENV{CXXFLAGS}  -o0 -Wall  -g2  -ggdb") 
 #定义Release编译参数
SET(CMAKE_CXX_FLAGS_RELEASE  "$ENV{CXXFLAGS}  -o3 -Wall ")
#gdb 调试选项[end]
#######################################################################
#将 server.cpp 赋值给 SRC_LIST 变量，也可以指定多个源文件，用空格隔开
# SET(SRC_LIST hello.cpp add.cpp sub.cpp)
SET(SRC_LIST survey.cpp)
#######################################################################
#将 -lnanomsg -lanl  -lpthread 赋值给DYN_LIB_LINK变量(用空格隔开)
SET(DYN_LIB_LINK  -lnanomsg -lanl  -lpthread)

#######################################################################
#使用相对路径
SET (CMAKE_USE_RELATIVE_PATHS ON)
#######################################################################
#用于查找头文件的文件夹,如果文件夹路径是相对路径,则认为该路径是基于当前源文件的路径。
#include_directories(../socket/nanomsg) 
#收集指定目录中所有源文件的名称，并将列表存储在提供的<variable>变量中。
#aux_source_directory(../socket/nanomsg  NANOMSG) 

#######################################################################

#用于查找头文件的文件夹,如果文件夹路径是相对路径,则认为该路径是基于当前源文件的路径。
include_directories(../../build/include/nanomsg) 
#添加需要链接的库文件目录
link_directories(../../build/lib)
#######################################################################

# 输出打印构建目录
MESSAGE(STATUS "WELCOME TO  YOU!")
# 输出打印资源目录
MESSAGE(STATUS "This is PROJECT_NAME " ${PROJECT_NAME})
# 输出打印资源目录，与HELLO_SOURCE_DIR 一样 
MESSAGE(STATUS "This is PROJECT_SOURCE_DIR " ${PROJECT_SOURCE_DIR})
# 输出打印 CMake 资源目录，与 PROJECT_SOURCE_DIR 一样 
MESSAGE(STATUS "This is CMAKE_SOURCE_DIR " ${CMAKE_SOURCE_DIR})
# 输出打印资源目录
MESSAGE(STATUS "This is PROJECT_BINARY_DIR " ${PROJECT_BINARY_DIR})
#######################################################################

add_executable(${PROJECT_NAME}  ${SRC_LIST}  ${NANOMSG})

#######################################################################
#设置要链接的库文件的名称
target_link_libraries(${PROJECT_NAME}  ${DYN_LIB_LINK})



