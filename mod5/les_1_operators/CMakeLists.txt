cmake_minimum_required(VERSION 3.6)
project(les_1_operators)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES main.cpp foo.h file1.cpp file1.h)
add_executable(les_1_operators ${SOURCE_FILES})