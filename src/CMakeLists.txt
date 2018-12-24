cmake_minimum_required(VERSION 3.0)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

project(midnight)

add_executable(
    midnight
    midnight.cpp
    Engine.cpp
    Engine.h
    Character.cpp
    Character.h
)