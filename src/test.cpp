#include "doctest.h"
#include "lib.hpp"

using namespace std;

TEST_CASE("simpleTest"){
    int a = 1;
    REQUIRE(a == 1);
}

TEST_CASE("Test"){
    int a = 2;
    REQUIRE(a == 2);
}
