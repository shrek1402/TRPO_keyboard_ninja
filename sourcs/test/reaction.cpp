#include <cmath>
#include "../../third/catch2/catch.hpp"
double reaction(int _sec, int result);

TEST_CASE("TEST_REACTION", "[int]")
{
    REQUIRE(reaction(10, 2) == Approx(5.0).epsilon(0.01));
    REQUIRE(reaction(10, 3) == Approx(3.33).epsilon(0.01));
    REQUIRE(reaction(10, 0) == reaction(10, 0));
}