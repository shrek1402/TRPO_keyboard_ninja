#include <string>
#include <fstream>

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
TEST_CASE("TEST_PRINT_WELCOME_PANEL", "[check]") {
  REQUIRE(printWelcomePanel("../../bin/Welcome.txt") == Approx(0));
  CHECK(printWelcomePanel("../../bin/temp.txt") == Approx(0));
}