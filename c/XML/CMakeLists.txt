cmake_minimum_required(VERSION 3.14)
project(XML C)
# 链接库
link_libraries(libxml2.so)
set(CMAKE_C_STANDARD 99)

add_executable(XML main.c)