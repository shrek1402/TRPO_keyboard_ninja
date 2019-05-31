#include "test.h"


int Lessen1(std::string _dataFile, int row, int col, int Lessen) {

  std::ifstream dataFile;
  dataFile.open(_dataFile);
  if (!dataFile.is_open()) {
    return 2;
  } else
    return 1;  
}

TEST_CASE("TEST_LESSEN", "[int]") {
  REQUIRE(Lessen1("../sourcs/data/level3.txt", 10, 2, 3) == 1);
  REQUIRE(Lessen1("../sourcs/data/abc.txt", 10, 2, 2) == 2);
}