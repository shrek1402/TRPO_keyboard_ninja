#include "../../third/catch2/catch.hpp"

int GetString(std::string file, std::string array[100]);

TEST_CASE("GetStringTest", "[Num_tests]")
{
    std::string array[100];
    REQUIRE(GetString("bin/data/Numbers.txt", array) == 1);
    REQUIRE(GetString("bin/data/Calculator.txt", array) == 1);
    REQUIRE(GetString("bin/data/Equation.txt", array) == 1);
    REQUIRE(GetString("bin/data/EquationAnswers.txt", array) == 1);
}

int CalcResult(
        int A0,
        int A1,
        double& result0,
        double& result1,
        int flag,
        int test_flag);

TEST_CASE("CalcResultTest", "[Num_tests]")
{
    double a = 0, b = 0;
    REQUIRE(CalcResult(30, 0, a, b, 0, 0) == 1);
    REQUIRE(CalcResult(0, 60, a, b, 0, 1) == 2);
    REQUIRE(CalcResult(60, 30, a, b, 1, 0) == 2);
    REQUIRE(CalcResult(180, 0, a, b, 1, 1) == 3);
    REQUIRE(CalcResult(120, 0, a, b, 2, 0) == 4);
    REQUIRE(CalcResult(30, 120, a, b, 2, 1) == 4);
}