#include "pch.h"
#include <ctime>
using namespace std;

int main(int argc, char **argv) {
  int row, col;
  initscr();
  start_color();

  init_pair(1, COLOR_WHITE, COLOR_BLACK);
  init_pair(2, COLOR_GREEN, COLOR_BLACK);
  init_pair(3, COLOR_RED, COLOR_BLACK);
  attron(COLOR_PAIR(1));

  getmaxyx(stdscr, row, col);
  printRamka(row, col);
  printWelcomePanel("Welcome.txt", row, col);
  keypad(stdscr, TRUE);

  while (1) {
    switch (mainMenu(row, col)) {
    case 1: {
      speedMode(slozhnost(row, col), row, col);
      break;
    }
    case 2: {
      int tmp = menu_lesson(row, col);
      Select_level(tmp, row, col);
      break;
    }
    case 3: {
      int item = Num_Menu(row, col);
      Select_item(item, row, col);
      break;
    }
    case 4:
      return 0;
    }
  }

  getch();
  endwin();
  return 0;
}
