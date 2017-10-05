cmake_minimum_required(VERSION 3.5.2)

project(qsort)
set(CMAKE_CXX_STANDARD 14)

add_executable(${PROJECT_NAME} qsort.hpp main.cpp)
