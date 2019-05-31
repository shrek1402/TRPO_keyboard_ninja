#include "test.h"
const unsigned int SEK = 60;

int Lessen1(std::string _dataFile, int row, int col, int Lessen) {


  std::ifstream dataFile(_dataFile);
  std::vector<std::string> vec;
  double max_leg = 0.0;
  dataFile.open(_dataFile);
  if (!dataFile.is_open())
  { 
      return 2;
  }
  return 1;
  while (!dataFile.eof()) {
    std::string temp;
    std::getline(dataFile, temp);
    max_leg += temp.length();
    vec.push_back(temp);
  }

  unsigned int startTime = clock();
  unsigned int endTime = startTime, DOP = 0;
  int ch;
  int temp, error = 0;
  long long unsigned int i = 0;
  std::string tempA;
  bool flag = 1;
  int x_temp = 0, level = 1;
  double proz = 0.0, sum_proz = 0.0;

  proz = 100 / max_leg;

  do {
    if ((ch = getch()) == ERR) {
      if (flag) {
        tempA = vec.at(level - 1);
        x_temp = (col - tempA.length()) / 2;
        flag = 0;
      }
    } else {
      temp = ch;
      flag = 0;

      if (tempA[i] == temp) {
        sum_proz += proz;


        x_temp++;
        i++;
        if (i == tempA.length()) {
          DOP += 3;
          flag = 1;
          i = 0;

          if (level == 8) {
            break;
          }
          level++;
        }
      } else {
        DOP -= 1;
        error++;
      }
    }
  } while (endTime < startTime + (DOP + SEK) * 1000);
}

TEST_CASE("TEST_LESSEN", "[int]") {
  REQUIRE(Lessen1("../sourcs/data/level3.txt",10,2,3) == 1);
  REQUIRE(Lessen1("../sourcs/data/abc.txt",10,2,2) == 2);
}