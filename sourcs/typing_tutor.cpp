#include "pch.h"

int level(int row, int col)
{
	erase();
	printRamka(row, col);
	std::vector<std::string> mStr = {
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

void Select_level(int slozh, int row, int col)
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

int level_1_to_5(string _dataFile, int row, int col)
{
	std::ifstream dataFile(_dataFile);
	std::vector<std::string> vec;

	while (!dataFile.eof())
	{
		std::string temp;
		std::getline(dataFile, temp);
		vec.push_back(temp);
	}
	unsigned int result = 0;
	unsigned int startTime = clock();
	unsigned int endTime = startTime;
	nodelay(stdscr, TRUE);
	int ch;
	int temp;
	long long unsigned int i = 0;
	std::string tempA;
	bool flag = 1;
	int x, y, x_temp = col / 2, level = 1;
	int popitki = 0;

	do
	{
		if ((ch = getch()) == ERR)
		{
			if (flag == 1)
			{
				move(row / 2, col / 2);
				tempA = vec.at(level);
				printw("%s", tempA.c_str());
				flag = 0;
				popitki++;
			}
			endTime = clock();
			move(1, 5);
			printw("%d ms", endTime - startTime);
			move(1, 1);
			printw("level %d", level);
		}
		else
			temp = ch;
		flag = 0;

		if ((inttempA[i]==temp)
		{
			x_temp++;
			move(row / 2, x_temp);
			addch(temp.at(i) | A_DIM);
			i++;
			if (i == tempA.length())
			{
				flag = 1;
				i = 0;
				level++;
				if (level == 6)
				{
					string mesg="Now the following levels are open for you!";
					mvwprintw(stdscr, row / 2, (col - strlen(mesg)) / 2, "%s",mesg);
				}
			}
		}

	} while (endTime < startTime + SEC * 1000);
}