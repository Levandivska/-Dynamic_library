cmake_minimum_required(VERSION 3.8)
project(untitled5)

set(CMAKE_C_STANDARD 99)

set(SOURCE_FILES main.c my_lib.c my_lib.h)
add_executable(untitled5 ${SOURCE_FILES})