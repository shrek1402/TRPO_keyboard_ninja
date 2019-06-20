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
    REQUIRE(GetString("data/Numbers.txt", array) == 1);
    REQUIRE(GetString("data/Calculator.txt", array) == 1);
    REQUIRE(GetString("data/Equation.txt", array) == 1);
    REQUIRE(GetString("data/EquationAnswers.txt", array) == 1);
}