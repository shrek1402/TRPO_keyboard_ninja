#include "../../third/catch2/catch.hpp"
#include <cmath>
double reaction(int _SEC, int result)
{
    if (!result)
        return 0;

    return (double)_SEC / result;
}

TEST_CASE("TEST_REACTION", "[int]")
{
    REQUIRE(reaction(10, 2) == Approx(5.0).epsilon(0.01));
    REQUIRE(reaction(10, 3) == Approx(3.33).epsilon(0.01));
    REQUIRE(reaction(10, 0) == reaction(10, 0));
}