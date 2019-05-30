#include <iostream>
#include "../../third/catch2/catch.hpp"
using namespace std;

int num_menu(int ch) {
    int Arr[4];
    Arr[0] = 0;
    Arr[1] = 1;
    Arr[2] = 2;
    Arr[3] = 3;
    switch(ch) {
        case 0: {
            return Arr[0];
            break;
        }
        case 1: {
            return Arr[1];
            break;
        }
        case 2: {
            return Arr[2];
            break;
        }
        case 3: {
            return Arr[3];
            break;
        }
    }
    return 4;
}

TEST_CASE("Test [1]", "[SpeedNum]")
{
    REQUIRE(num_menu(0) == 0);
    REQUIRE(num_menu(1) == 1);
    REQUIRE(num_menu(2) == 2);
    REQUIRE(num_menu(3) == 3);
    REQUIRE(num_menu(5) == 4);
}

int Select_item(int item)
{
    int A[3] = {0, 0, 0};
    switch (item) {
    case 1: {
        SpeedNum(row, col, A);
        ResultNum(row, col, A, 0);
        return 1;
        break;
    }
    case 2: {
        Solving(row, col, A);
        ResultNum(row, col, A, 1);
        return 2;
        break;
    }
    case 3: {
        Calculator(row, col, A);
        ResultNum(row, col, A, 2);
        return 3;
        break;
    }
    case 4: {
        return 4;
        break;
    }
    }
    return 0;
}

TEST_CASE("Test [1]", "[SpeedNum]")
{
    REQUIRE(Select_item(1) == 1);
    REQUIRE(Select_item(2) == 2);
    REQUIRE(Select_item(3) == 3);
    REQUIRE(Select_item(4) == 4);
    REQUIRE(Select_item(5) == 0);
}