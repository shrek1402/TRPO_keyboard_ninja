#include "../../third/catch2/catch.hpp"

double percent(double max_leg);
        TEST_CASE("TEST_RESUL", "[check]")
{
    REQUIRE(percent (100.0) == Approx(1.0));
    REQUIRE(percent (20.0) == Approx(5.0));
    REQUIRE(percent (25.0) == Approx(4.0));
}