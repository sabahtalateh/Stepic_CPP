cmake_minimum_required(VERSION 3.6)
project(less7_copy_constructors)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES main.cpp String.cpp String.h IntArray.cpp IntArray.h)
add_executable(less7_copy_constructors ${SOURCE_FILES})