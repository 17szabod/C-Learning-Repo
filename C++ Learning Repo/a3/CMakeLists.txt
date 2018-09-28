cmake_minimum_required(VERSION 3.8)
project(a3)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES main.cpp a3.hpp a3.cpp a3.hpp)
add_executable(a3 ${SOURCE_FILES})