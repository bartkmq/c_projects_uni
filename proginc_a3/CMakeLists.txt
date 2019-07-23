cmake_minimum_required(VERSION 3.6)
project(proginc_a3)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES main.cpp)
add_executable(proginc_a3 ${SOURCE_FILES})