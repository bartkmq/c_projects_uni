cmake_minimum_required(VERSION 3.6)
project(proginc_aufgabe_a)

set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -Wall")

set(SOURCE_FILES main.c Datum.c Datum.h)
add_executable(proginc_aufgabe_a ${SOURCE_FILES})
target_link_libraries(proginc_aufgabe_a m)