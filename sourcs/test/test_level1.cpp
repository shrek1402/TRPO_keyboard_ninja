#ifndef PCH_H
#define PCH_H
#define PDC_DLL_BUILD

#ifdef _WIN32
#include <curses.h>
#else
#include <ncurses.h>
#endif
#include <fstream>
#include <string>

#include "../../third/catch2/catch.hpp"

int dopusk(int row, int col, int Lessen, unsigned int endTime,
            unsigned int startTime, double sum_proz, int error) {
  erase();
  start_color();
  init_pair(Correct_green, COLOR_GREEN, COLOR_BLACK);
  init_pair(Basic_style, COLOR_WHITE, COLOR_BLACK);
  init_pair(Wrong_red, COLOR_RED, COLOR_BLACK);
  attron(COLOR_PAIR(Basic_style));
  printRamka(row, col);
  int size_x, size_y, xx, yy;
  size_x = 80;
  size_y = 20;
  xx = 20;
  yy = 15;
  WINDOW *win5 = newwin(size_y, size_x, yy, xx);
  if (sum_proz < 100) {
    attron(COLOR_PAIR(Wrong_red));
    move((row - 4) / 2 - 2, (col - 26) / 2);
    printw("Time's up, try again!");
    return 1;
  } else {
    attron(COLOR_PAIR(Correct_green));
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
  attron(COLOR_PAIR(Basic_style));
}
TEST_CASE("TEST_PROP", "[int]") {
  REQUIRE(reaction(10,2, 3, 4, 5, 6, 7) == 1;
  REQUIRE(reaction(10,2, 3, 4, 5, 6, 100) == 2;
}