#include "doctest.h"
#include <iostream>
#include <iomanip>
#include <vector>
#include <string>
#include <ctime>
#include "lib.hpp"

using namespace std;

TEST_CASE("simpleTest"){
    int a = 1;
    REQUIRE(a == 1);
}