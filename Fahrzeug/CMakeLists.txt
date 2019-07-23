cmake_minimum_required(VERSION 3.6)
project(Fahrzeug)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES main.cpp Fahrzeug.cpp Fahrzeug.h)
add_executable(Fahrzeug ${SOURCE_FILES})