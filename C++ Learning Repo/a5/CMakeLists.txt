cmake_minimum_required(VERSION 3.8)
project(a5)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES main.cpp SmartInteger.hpp SmartInteger.cpp)
add_executable(a5 ${SOURCE_FILES})