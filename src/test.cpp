#include "doctest.h"
#include "lib.hpp"

using namespace std;

TEST_CASE("simpleTest"){
    int a = 1;
    REQUIRE(a == 1);
}

template<class T>
class Point
{
public:
    T x;
    T y;

    Point(T x = 0, T y = 0)
    {
        this->x = x;
        this->y = y;
    }
    ~Point() {};

    bool operator < (Point p)
    {
        return (this->x < p.x) and (this->y < p.y);
    }

    bool operator > (Point p)
    {
        return (this->x > p.x) and (this->y > p.y);
    }

    bool operator == (Point p)
    {
        return (this->x == p.x) and (this->y == p.y);
    }
};

