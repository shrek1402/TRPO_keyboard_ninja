#include "../../third/catch2/catch.hpp"
int resultat(
        int row,
        int col,
        int Lessen,
        time_t endTime,
        time_t startTime,
        double sum_proz,
        int error);
        TEST_CASE("TEST_RESUL", "[check]")
{
    REQUIRE(resultat(200, 100, 2, 110, 121, 100.0, 5) == 2);
    REQUIRE(resultat(200, 100, 2, 110, 121, 87.5, 5) == 1);
}