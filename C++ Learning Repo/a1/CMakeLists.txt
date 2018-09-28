cmake_minimum_required(VERSION 3.8)
project(new368)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES a1.cpp a1.h ../a2/a2.cpp ../a2/a2.h)
add_executable(new368 ${SOURCE_FILES})