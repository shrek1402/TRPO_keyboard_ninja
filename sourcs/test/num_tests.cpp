#include "../../third/catch2/catch.hpp"

int GetString(std::string file, std::string array[100]);

TEST_CASE("GetStringTest", "[Num_tests]")
{
    std::string array[100];
    REQUIRE(GetString("data/Numbers.txt", array) == 1);
    REQUIRE(GetString("data/Calculator.txt", array) == 1);
    REQUIRE(GetString("data/Equation.txt", array) == 1);
    REQUIRE(GetString("data/EquationAnswers.txt", array) == 1);
}