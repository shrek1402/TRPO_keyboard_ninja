#include "../../third/catch2/catch.hpp"
int getYY(int row, int ySize);
TEST_CASE("TEST_getYY", "[check]")
{
    REQUIRE(getYY(15, 2) == 8);
	REQUIRE(getYY(15, 2) != 5);
}