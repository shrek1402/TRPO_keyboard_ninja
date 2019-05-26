#include "pch.h"

int Num_Menu(int row, int col)
{
	erase();
	printRamka(row, col);
	std::vector<std::string> N_Menu = {
		"Exercises with numbers:",
		"1. Speed Number",
		"2. Solving equations",
	 	"3. Calculator",
		"4. Back to main menu"
	};

	noecho();
	keypad(stdscr, TRUE);
	return printMenu(N_Menu);
}