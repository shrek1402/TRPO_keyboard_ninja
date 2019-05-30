#include "test.h"

int resultat (int row, int col, int Lessen, unsigned int endTime,
            unsigned int startTime, double sum_proz, int error) {
 


  if (sum_proz < 100) {

    return 1;
  } else {
    return 2;
  }

}

TEST_CASE("TEST_RESULTAT", "[int]") {
  REQUIRE(resultat(10,2, 3, 4, 5, 6, 7) == 1);
  REQUIRE(resultat(10,2, 3, 4, 5, 6, 100) == 2);
}