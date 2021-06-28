#include "doctest.h"
#include "lib.hpp"

using namespace std;

int add(int a, int b) {
return a+b;
}

TEST_CASE("testing add func") {
CHECK(add(0, 0) == 0);
CHECK(add(1, 0) == 1);
CHECK(add(1, 1) == 2);
CHECK(add(0, -1) == -1);
CHECK(add(-1, -1) == -2);
}

TEST_CASE("Test coor"){
  int x[2] = {1,2};
  auto [a,b] = x;
  CAPTURE(a);
}

TEST_CASE("simpleTest"){
    int a = 1;
    REQUIRE(a == 1);
}

TEST_CASE("Test"){
    int a = 2;
    REQUIRE(a == 2);
}