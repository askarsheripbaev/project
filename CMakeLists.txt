cmake_minimum_required(VERSION 3.0.0)
project(pairs VERSION 0.1.0)

add_library(default INTERFACE)
target_compile_features(default INTERFACE cxx_std_17)

set(CMAKE_CXX_STANDARD 17)

enable_testing()
add_subdirectory(external/doctest)
include(external/doctest/doctest.cmake)
include_directories(external/doctest)

add_subdirectory(src)