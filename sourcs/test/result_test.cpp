#include "../../third/catch2/catch.hpp"
int resultat(
        int row,
        int col,
        int Lessen,
        unsigned int endTime,
        unsigned int startTime,
        double sum_proz,
        int error);
TEST_CASE("TEST_RESULT", "[check]")
{
    REQUIRE(resultat(100, 200, 2, 100, 0, 100, 5) == 2);
    REQUIRE(resultat(100, 200, 2, 100, 0, 87, 5) == 1);
}