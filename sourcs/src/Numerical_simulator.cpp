#include "pch.h"

int Num_Menu(int row, int col)
{
	erase();
	printRamka(row, col);
	std::vector<std::string> N_Menu = {
		"Exercises with numbers:",
		"Speed Number",
		"Solving equations",
	 	"Calculator",
		"Back to main menu"
	};

	noecho();
	keypad(stdscr, TRUE);
	return printMenu(N_Menu);
}