cmake_minimum_required(VERSION 3.6)
project(proginc_aufgabe_a_v2)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES main.c Datum.c Datum.h)
add_executable(proginc_aufgabe_a_v2 ${SOURCE_FILES})
target_link_libraries(proginc_aufgabe_a_v2 m)