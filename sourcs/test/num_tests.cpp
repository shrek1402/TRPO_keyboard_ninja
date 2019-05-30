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