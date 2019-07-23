cmake_minimum_required(VERSION 3.6)
project(linked_list)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES main.cpp LinkedList.h)
add_executable(linked_list ${SOURCE_FILES})