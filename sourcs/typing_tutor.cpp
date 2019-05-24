#include "pch.h"

int level (int row, int col)
{
	erase();
    printRamka(row, col);
	std::vector <std::string> mStr = {
		"  Select the level", 
		"1. level 1 to 5",
		"2. level 6 to 10",
		"3. level 11 to 15",
        "4. Backward"
		
	};
    
	noecho();
	keypad(stdscr, TRUE);
	return printMenu(mStr);
}

void Select_level (int slozh, int row, int col)
{
	erase();
    printRamka(row, col);
	
	switch (slozh) 
	{
        case 1:
		{	
			break;
		}
        
		case 2:
		{	
			break;
		}
			
		case 3:
		{		
			break;
		}
		case 4:
			break;
    }	
}