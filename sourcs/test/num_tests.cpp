#include "../../third/catch2/catch.hpp"
#include "../src/pch.h"
using namespace std;

int GetString(string file, string array[100])
{
    ifstream File(file);
    if (!(File.is_open())) {
        return 0;
    }
    string str;
    int i = 0;
    while (!File.eof()) { //заполняем массив строками из файла
        getline(File, str);
        array[i] = str;
        i++;
    }
    return 1;
}

TEST_CASE("TEST_GETSTRING", "[check]")
{
    string array[100];
    REQUIRE(GetString("bin/data/Numbers.txt", array) == 1);
    REQUIRE(GetString("bin/data/Calculator.txt", array) == 1);
    REQUIRE(GetString("bin/data/Equation.txt", array) == 1);
    REQUIRE(GetString("bin/data/EquationAnswers.txt", array) == 1);
}

int Time(int row, int col, int Timer, int EndTime, int StartTime)
{
    if (((StartTime + Timer) - EndTime) < 16) {
        EndTime = time(NULL);
    } else {
        EndTime = time(NULL);
    }
    return (EndTime - StartTime);
}

TEST_CASE("TEST_TIMEEND", "[check]")
{
    string array[100];
    REQUIRE(Time(100, 100, 30, time(NULL), time(NULL)) == 0);
}