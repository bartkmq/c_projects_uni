cmake_minimum_required(VERSION 3.6)
project(proginc_aufgabe_b_teil_2_v2)

set(CMAKE_C_STANDARD 99)

set(SOURCE_FILES main.c area.c area.h ameise.c ameise.h)
add_executable(proginc_aufgabe_b_teil_2_v2 ${SOURCE_FILES})