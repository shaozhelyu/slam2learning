cmake_minimum_required(VERSION 2.8)
project(coordinateTransform)
set(CMAKE_CXX_FLAGS "-std=c++11")
set(CMAKE_BUILD_TYPE "Debug")

include_directories("/usr/include/eigen3")
add_executable(coordinateTransform coordinateTransform.cpp)
