#include "pch.h"

int level (int row, int col)
{
	erase();
    printRamka(row, col);
	vector <std::string> mStr = {
		"  Select the level", 
		"1. level 1 to 5",
		"2. level 6 to 10",
		"3. level 11 to 15",
        "4. Backward"
		
	};
    	noecho();
	keypad(stdscr, TRUE);
	do{
		for(int i = 0; i < 5; i++){
			move(row/2 + i, col/2 - 9);
			if (i == c){
				
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