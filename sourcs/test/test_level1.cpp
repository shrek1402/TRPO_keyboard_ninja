#include "test.h"

int resultat (int row, int col, int Lessen, unsigned int endTime,
            unsigned int startTime, double sum_proz, int error) {
  erase();
  start_color();
  init_pair(1, COLOR_GREEN, COLOR_BLACK);
  init_pair(2, COLOR_WHITE, COLOR_BLACK);
  init_pair(3, COLOR_RED, COLOR_BLACK);
  attron(COLOR_PAIR(3));
  int size_x, size_y, xx, yy;
  size_x = 80;
  size_y = 20;
  xx = 20;
  yy = 15;
  WINDOW *win5 = newwin(size_y, size_x, yy, xx);
  if (sum_proz < 100) {
    attron(COLOR_PAIR(3));
    move((row - 4) / 2 - 2, (col - 26) / 2);
    printw("Time's up, try again!");
    return 1;
  } else {
    attron(COLOR_PAIR(1));
    move((row - 4) / 2 - 2, (col - 26) / 2);
    printw("Well done keep learning!");
    return 2;
  }

  move(1, (col - 4) / 2);
  printw("Lessen %d", Lessen);
  move((row - 4) / 2, (col - 26) / 2);
  printw("Execution time %d ms", endTime - startTime);
  move((row - 4) / 2 + 2, (col - 26) / 2);
  printw("You passed %3.2f percent of the lesson", sum_proz);
  move((row - 4) / 2 + 4, (col - 26) / 2);
  printw("Incorrectly entered letters %d", error);
  box(win5, 0, 0);
  wrefresh(win5);
  getch();
  attron(COLOR_PAIR(3));
}

TEST_CASE("TEST_RESULTAT", "[int]") {
  REQUIRE(reaction(10,2, 3, 4, 5, 6, 7) == 1;
  REQUIRE(reaction(10,2, 3, 4, 5, 6, 100) == 2;
}