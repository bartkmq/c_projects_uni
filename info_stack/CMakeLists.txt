cmake_minimum_required(VERSION 3.6)
project(info_stack)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES main.cpp kreis.cpp kreis.h)
add_executable(info_stack ${SOURCE_FILES})