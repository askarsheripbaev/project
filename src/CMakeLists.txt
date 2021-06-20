cmake_minimum_required(VERSION 3.10.0)

add_executable(pairs main.cpp lib.cpp)
#target_link_libraries(pairs)

add_executable(pairs_test test.cpp lib.cpp)
target_link_libraries(pairs_test PUBLIC doctest::doctest default)
doctest_discover_tests(pairs_test)