#include "../../third/catch2/catch.hpp"
using namespace std;
int getXX(int col, int xSize)
{
	return (col - xSize) / 2;
}
TEST_CASE("TEST_getXX", "[check]")
{
    REQUIRE(getXX(12, 6) == 3);
    REQUIRE(getXX(15, 5) == 5);
	REQUIRE(getXX(15, 1) != 5);
}