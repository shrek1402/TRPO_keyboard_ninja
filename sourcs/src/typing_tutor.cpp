#include "pch.h"
const unsigned int SEK = 30;
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

int level1(std::string _dataFile, int row, int col)
{
	std::ifstream dataFile(_dataFile);
	std::vector<std::string> vec;

	while (!dataFile.eof())
	{
		std::string temp;
		std::getline(dataFile, temp);
		vec.push_back(temp);
	}

	unsigned int startTime = clock();
	unsigned int endTime = startTime, DOP = 0;
	nodelay(stdscr, TRUE);
	int ch;
	int temp;
	long long unsigned int i = 0;
	std::string tempA;
	bool flag = 1;
	int x_temp = col / 2, level = 1;
	int popitki = 0;

	do
	{
		if ((ch = getch()) == ERR)
		{
			if (flag)
			{
				erase();
				printRamka(row, col);
				tempA = vec.at(level - 1);
				move(row / 2, (col - tempA.length()) / 2);
				printw("%s", tempA.c_str());
				x_temp = (col / 2) - (tempA.length() / 2);
				flag = 0;
				popitki++;
			}
			endTime = clock();
			move(1, 10);
			printw("%d ms", (DOP + SEK) * 1000 - (endTime - startTime));
			move(1, 1);
			printw("level %d", level);
		}
		else
		{
			temp = ch;
			flag = 0;

			if (tempA[i] == temp)
			{
				move(row / 2, x_temp);
				x_temp++;
				addch(tempA.at(i) | A_BLINK);
				i++;
				if (i == tempA.length())
				{
					DOP += 5;
					flag = 1;
					i = 0;

					if (level == 5)
					{
						break;
					}
					level++;
				}
			}
		}
	} while (endTime < startTime + (DOP + SEK) * 1000);

	nodelay(stdscr, FALSE);
	if (level == 5)
	{
		std::string abc = "You have passed all 5 levels, now the following are open for you!";
		erase();
		move(row / 2, (col - abc.length()) / 2);
		printw("%s", abc.c_str());
		getch();
		return level;
	}
	return level;
}

void Select_level(int slozh, int row, int col)
{
	int temp, dopusk = 0;

	erase();
	printRamka(row, col);

	switch (slozh)
	{
	case 1:
	{

		temp = level1("level1.txt", row, col);
		if (temp == 5)
		{
			dopusk = temp;
		}
		break;
	}

	case 2:
	{
		if (dopusk >= 5)
		{
		}
		break;
	}

	case 3:
	{
		if (dopusk >= 10)
		{
		}
		break;
	}
	case 4:
		break;
	}
}

