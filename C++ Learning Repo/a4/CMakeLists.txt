cmake_minimum_required(VERSION 3.8)
project(a4)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES main.cpp processStudent.cpp processStudent.hpp Student.hpp UndergradStudent.hpp GradStudent.hpp Student.cpp UndergradStudent.cpp GradStudent.cpp)
add_executable(a4 ${SOURCE_FILES})