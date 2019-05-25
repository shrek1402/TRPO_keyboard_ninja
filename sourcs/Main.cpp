#include "pch.h"

#include <ctime>

#define PDC_DLL_BUILD
int mainMenu(int row, int col);
int printRamka(int _row, int _col);
int slozhnost(int row, int col);
void speedMode(int slozh, int row, int col);
int lewel (int row, int col);
void lewel_select(int slozh, int row, int col);

int printWelcomePanel(string _str, int row, int col)
{
    ifstream myTextFile;
    myTextFile.open(_str);
    if (!myTextFile.is_open())
        return 1; 
    move(row / 2, col / 2);
    printw("Hello");
	refresh();
	getch(); // TODO time
    myTextFile.close();
    return 0;
}
int main(int argc, char** argv)
{
    int row, col;
    initscr();
    getmaxyx(stdscr, row, col);
    printRamka(row, col);
    printWelcomePanel(argv[1], row, col);

    while (1) {
        switch (mainMenu(row, col)) {
        case 1:{
			int temp = slozhnost(row, col);
			speedMode(temp, row, col);
			break;
		}
        case 2:
        	{
        	int tmp = lewel (row, col);	
        	lewel_select(tmp, row, col);
			}
        case 3:
        case 4:
            return 0;
        }
    }

    getch();
    endwin();
    return 0;
}