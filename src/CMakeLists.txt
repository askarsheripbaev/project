cmake_minimum_required(VERSION 3.10.0)
project(src CXX)
include(${CMAKE_CURRENT_LIST_DIR}/../cmake/Tester.cmake)
auto_tester(src pairs.cpp test.cpp)

add_library(Catch2)
add_library(cmake)
add_library(include iostream)
