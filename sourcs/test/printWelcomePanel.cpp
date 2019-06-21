#include <string>

#include "../../third/catch2/catch.hpp"

int printWelcomePanel(std::string _str, int row, int col);

TEST_CASE("TEST_PRINT_WELCOME_PANEL", "[check]")
{
    REQUIRE(printWelcomePanel("data/__ERROR__/temp.txt",10,20) != 0);
    REQUIRE(printWelcomePanel("data/Welcome.txt",10,20) == 0);
}