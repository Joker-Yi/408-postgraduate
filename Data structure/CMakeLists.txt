cmake_minimum_required(VERSION 3.19)
project(Data_structure)

set(CMAKE_CXX_STANDARD 11)

include_directories(.)

#add_executable(Data_structure
#        linearList/seqList_dynamic.cpp)

# 遍历项目根目录下所有的 .cpp 文件
file (GLOB files *.cpp */*.cpp)
foreach (file ${files})
#    string(REGEX REPLACE ".+/(.+)\\..*" "\\1" exe ${file}) #run配置文件 文件名命名
    string(REGEX REPLACE ".+/(.+)/(.+)\\..*" "\\1-\\2" exe ${file})
    add_executable (${exe} ${file})
    message (\ \ \ \ --\ src/${exe}.cpp\ will\ be\ compiled\ to\ bin/${exe})
endforeach ()

## 如果你只需要根目录下的 test 文件夹的所有 .cpp 文件
#file (GLOB files test/*.cpp)
## 如果你只有两层目录的话
#file (GLOB files *.cpp */*.cpp)
## 同理，三层的话
#file (GLOB files *.cpp */*.cpp */*/*.cpp)
#
## 官方提供了一种递归的方法
## 这样在运行框会多一个 CMakeCXXCompilerId，不过无伤大雅
#file (GLOB_RECURSE files *.cpp)