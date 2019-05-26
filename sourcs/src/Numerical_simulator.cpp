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

void Select_item (int item, int row, int col) {
	erase();
	printRamka(row, col);

	switch(item){
		case 1: {
		//	SpeedNum();
			break;
		}
		case 2: {
		//	Solving();
			break;
		}
		case 3: {
		//	Calculator();
			break;
		}
		case 4: {
			break;
		}
	}
}