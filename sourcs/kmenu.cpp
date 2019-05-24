#include "pch.h"

constexpr auto VERSION = "Beta v1.0";
constexpr unsigned int SEC = 1;


long long unsigned int printMenu(std::vector <std::string>& _vec)
{
	long long unsigned int c = 1;
	int temp;
	int col, row;
	getmaxyx(stdscr, row, col);
	
	do{
		for(long long unsigned int i = 0; i < _vec.size(); i++){
			move(row/2 + i, col/2 - 9);
			
			if (i == c){
				for (long long unsigned int j=0; j< _vec[i].length(); j++)
				addch(_vec[i][j] | A_BLINK);
			}
			else{
				printw("%s", _vec[i].c_str());
			}
		}
		
		if ((temp = getch()) == KEY_UP){
				if (c != 1)
					c--;
				else
					c = 4;
		}
		else if (temp == KEY_DOWN){
			if (c != 4)
				c++;
			else
				c = 1;
		}
		refresh();
	}while(temp != '\n');
	return c;
}

bool razmer()
{
	int col, row;
	getmaxyx(stdscr, row, col);
	if (row <  10) throw "Uvelich visotu okna";
	if (col < 40) throw "Uvelich shirinu okna";
	return true;
}

int mainMenu(int row, int col)
{
    erase();
    printRamka(row, col);
	std::vector <std::string> mStr = {
		"    Menu",
		"1. Speed mode",
		"2. typing tutor",
		"3. Blind seal mode",
		"4. Exit"
	};

	noecho();
	keypad(stdscr, TRUE);
	
	return printMenu(mStr);
}
int printRamka(int _row, int _col)
{
	curs_set(0);
	refresh();
	WINDOW *win = newwin(3, _col, 0, 0);
	box(win,0,0);
	
	WINDOW *win1 = newwin(_row - 3, _col, 3, 0); 
	box(win1, 0, 0);
	
	mvaddstr(1, _col - 10, _VERSION);
	wrefresh(win1);
	wrefresh(win);
    return 0;
}

int slozhnost(int row, int col)
{
	erase();
    printRamka(row, col);
	vector <std::string> mStr = {
		"  Slozhn", // TODO eng
		"1. Eazy",
		"2. Normal",
		"3. Hard",
		"4. Back"
	};

	noecho();
	keypad(stdscr, TRUE);
	
	return printMenu(mStr);
}

void resultTabl(int result, int popitki)
{
	erase();
	
	int row,col;
	getmaxyx(stdscr, row, col);
	printRamka(row, col);
	int ySize = 9,
		xSize = col -(row - ySize +3 +2),
		yy = (row - ySize - 5) / 2 + 4,
		xx = (col - xSize) / 2;
			if ((col - xSize)%2 != 0)
				xSize++;
			if ((row - ySize)%2 == 0)
				ySize++;
		
		int sm;
		result > 0? 
			sm = 6:
			sm = 7;
			
		WINDOW *win = newwin(ySize, xSize, yy, xx);
		move(yy + 2, xx+xSize/2 - sm);
		printw("Result: %d", result);
		move(yy + 3, xx+xSize/2 -sm);
				// TODO add: time, % ...
		result > 0? 
			printw("MOLODEC! :)"):
			printw("NE MOLODEC! :(");
		
		move(yy + 4, xx+xSize/2 -sm);
			printw("Reaction: %f", _SEC/result*1.0);
			
		box(win,0,0);
		wrefresh(win);
		getch();
}