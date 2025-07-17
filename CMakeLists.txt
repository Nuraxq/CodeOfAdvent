cmake_minimum_required(VERSION 3.30.5)
project(CodeOfAdvent)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(CodeOfAdvent
        main.cpp
        Task_one.cpp
        cmake-build-debug/Task_two.cpp
        cmake-build-debug/Task_two.h
)