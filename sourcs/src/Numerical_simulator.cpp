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
			SpeedNum(row, col);
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

int SpeedNum(int row, int col) {
	
	nodelay(stdscr, TRUE);
	unsigned int StartTime = clock(), EndTime = clock(), otvet=0;
	char ch;
	ifstream Numbers("Numbers.txt");
	vector<string> vector;
	string str1, str2;
	erase();
	printRamka(row, col);
	while (!Numbers.eof()){
		getline(Numbers, str1);
		vector.push_back(str1);
	}

		do {
			if ((ch = getch()) == ERR)
			{
			move(1, 2);
			printw("Time left: ");
			EndTime = clock();
			move(1, 13);
			printw("%d sec", (30 * 1000 - (EndTime - StartTime))/1000);
			}
	
	
	} while (EndTime < StartTime + 30*1000);
	nodelay(stdscr, FALSE);
return otvet;
}