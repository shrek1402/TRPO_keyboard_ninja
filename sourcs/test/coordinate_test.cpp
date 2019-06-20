#include "../../third/catch2/catch.hpp"
int coordinate(int row)
{
    return (row - 4) / 2;
}
TEST_CASE("TEST_COORDINATE", "[check]")
{
    REQUIRE(coordinate(100) == 48);
    REQUIRE(coordinate(200) == 98);
    REQUIRE(coordinate(350) == 173);
}