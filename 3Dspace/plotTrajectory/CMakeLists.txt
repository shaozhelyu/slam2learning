cmake_minimum_required(VERSION 2.8)
project(plotTrajectory)

set(CMAKE_BUILD_TYPE "Debug")
set(CMAKE_CXX_FLAGS "-std=c++11")

include_directories( "/usr/include/eigen3" )

find_package(Pangolin)
include_directories(${Pangolin_INCLUDE_DIRS})

add_executable(plotTrajectory plotTrajectory.cpp)
target_link_libraries(plotTrajectory ${Pangolin_LIBRARIES})
