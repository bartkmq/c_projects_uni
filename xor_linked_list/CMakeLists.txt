cmake_minimum_required(VERSION 3.6)
project(xor_linked_list)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES main.cpp LinkedListXor.hpp)
add_executable(xor_linked_list ${SOURCE_FILES})