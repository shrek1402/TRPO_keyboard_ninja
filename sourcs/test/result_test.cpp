#include "../../third/catch2/catch.hpp"
int percent (double max_leg);
        TEST_CASE("TEST_RESUL", "[check]")
{
    REQUIRE(percent (100.0) == 1.0);
    REQUIRE(percent (20.0) == 5.0);
    REQUIRE(percent (25.0) == 4.0);
}