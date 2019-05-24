#include "pch.h"

constexpr auto VERSION = "Beta v1.0";
constexpr unsigned int SEC = 1;


bool razmer()
{
	int col, row;
	getmaxyx(stdscr, row, col);
	if (row <  10) throw "Uvelich visotu okna";
	if (col < 40) throw "Uvelich shirinu okna";
	return true;
}

int printRamka(int _row, int _col)
{
	curs_set(0);
	refresh();
	WINDOW *win = newwin(3, _col, 0, 0);
	box(win,0,0);
	
	WINDOW *win1 = newwin(_row - 3, _col, 3, 0); 
	box(win1, 0, 0);
	
	mvaddstr(1, _col - 10, VERSION);
	wrefresh(win1);
	wrefresh(win);
    return 0;
}

int mainMenu(int row, int col)
{
	
    erase();
    printRamka(row, col);
	std::string mStr[5] = {
		"    Menu",
		"1. Speed mode",
		"2. Time mode",
		"3. Blind seal mode",
		"4. Exit"
	};
	
	int c = 1;
	//start_color();
	int temp;
	noecho();
	keypad(stdscr, TRUE);
	do{
		for(int i = 0; i < 5; i++){//TODO 5 ->size
			move(row/2 + i, col/2 - 9);
			if (i == c){
				//attron(A_BLINK);
				for (long long unsigned int j=0; j< mStr[i].length(); j++)
				addch(mStr[i][j] | A_BLINK);
			}
			else{
				printw("%s", mStr[i].c_str());
			}
		}
		temp = getch();
		if (temp == KEY_UP){
				if (c != 1)
					c--;
				else
					c = 4;
			}
		if (temp == KEY_DOWN){
			if (c != 4)
				c++;
			else
				c = 1;
		}
		refresh();
	}while(temp != '\n');
	return c;
}

int slozhnost(int row, int col)
{
	erase();
    printRamka(row, col);
	std::string mStr[5] = {
		"  Slozhn", // TODO eng
		"1. Eazy",
		"2. Normal",
		"3. Hard",
		"4. Back"
	};
}