cmake_minimum_required(VERSION 3.6)
project(test_0)

set(CMAKE_C_STANDARD 99)

set(SOURCE_FILES main.c)
add_executable(test_0 ${SOURCE_FILES})
target_link_libraries(test_0 m)