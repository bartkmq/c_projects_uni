cmake_minimum_required(VERSION 3.6)
project(proginc_integrieren)

set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -Wall -Werror")

set(SOURCE_FILES main.c integration.c integration.h)
add_executable(proginc_integrieren ${SOURCE_FILES})

target_link_libraries(proginc_integrieren m)