#include <fstream>
#include <string>

#include "../../third/catch2/catch.hpp"
using namespace std;
int printWelcomePanel(string _str)
{
    ifstream myTextFile;
    myTextFile.open(_str);
    if (!myTextFile.is_open())
        return 1;

    myTextFile.close();
    return 0;
}
TEST_CASE("TEST_PRINT_WELCOME_PANEL", "[check]")
{
    REQUIRE(printWelcomePanel("bin/data/Welcome.txt") == 0);
    REQUIRE(printWelcomePanel("../../bin/temp.txt") == 1);
}