cmake_minimum_required(VERSION 3.6)
project(les_2_methods)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES main.cpp point.h point.cpp string.cpp)
add_executable(les_2_methods ${SOURCE_FILES})