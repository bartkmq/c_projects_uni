cmake_minimum_required(VERSION 3.6)
project(dynamic_stack)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES main.cpp dynamic_stack.hpp)
add_executable(dynamic_stack ${SOURCE_FILES})