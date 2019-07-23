cmake_minimum_required(VERSION 3.6)
project(proginc_aufgabe_b_2)

set(CMAKE_C_STANDARD 99)

set(SOURCE_FILES main.c)
add_executable(proginc_aufgabe_b_2 ${SOURCE_FILES})
target_link_libraries(proginc_aufgabe_b_2 m)