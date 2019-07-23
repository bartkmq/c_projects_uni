cmake_minimum_required(VERSION 3.6)
project(proginc_a6)

set(CMAKE_C_STANDARD 99)

set(SOURCE_FILES main.c tipputils.h tipputils.c)
add_executable(proginc_a6 ${SOURCE_FILES})