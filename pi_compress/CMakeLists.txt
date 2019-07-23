cmake_minimum_required(VERSION 3.6)
project(pi_compress)

set(CMAKE_C_STANDARD 99)

set(SOURCE_FILES main.c pi.h)
add_executable(pi_compress ${SOURCE_FILES})
target_link_libraries(pi_compress m)