cmake_minimum_required(VERSION 3.6)
project(c99)

set(CMAKE_C_STANDARD 99)

set(SOURCE_FILES main.c)
add_executable(c99 ${SOURCE_FILES})