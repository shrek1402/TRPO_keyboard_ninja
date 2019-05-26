#include "pch.h"
const unsigned int SEK = 60;
int level(int row, int col)
{
	erase();
	printRamka(row, col);
	std::vector<std::string> mStr = {
		"Learning touch typing",
		"Lesson 1",
		"Lesson 2",
		"Lesson 3",
		"Backward"

	};

	noecho();
	keypad(stdscr, TRUE);
	return printMenu(mStr);
}

void dopusk(int row, int col, int Lessen, unsigned int endTime, unsigned int startTime, double sum_proz )
{
	printRamka(row, col);
	move (1,(col-8)/2);
	attron ( A_BOLD);
	printw("Lessen %d", Lessen);
	attron ( A_NORMAL);
	move (row/2,(col-12)/2);
	printw ("Passed %d ms",endTime-startTime);
	move (row/2+2,(col-38)/2);
	printw ("You passed %3.2f percent of the lesson", sum_proz);

	getch();
}

void level1(std::string _dataFile, int row, int col, int Lessen)
{
	std::ifstream dataFile(_dataFile);
	std::vector<std::string> vec;
	double max_leg = 0.0;
	while (!dataFile.eof())
	{
		std::string temp;
		std::getline(dataFile, temp);
		max_leg += temp.length();
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
	int x_temp = 0, level = 1;
	double proz = 0.0, sum_proz = 0.0;

	proz = 100 / max_leg;

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
				x_temp = (col / 2) - (tempA.length() / 2) - 1;
				flag = 0;
			}
			attron (A_BOLD);
			move(10, (col - 16) / 2);
			printw("%3.2f percent", sum_proz);
			endTime = clock();
			move(1, 10);
			printw("%d ms", (DOP + SEK) * 1000 - (endTime - startTime));
			move(1, 1);
			printw("Lessen %d", Lessen);
		}
		else
		{
			temp = ch;
			flag = 0;

			if (tempA[i] == temp)
			{
				sum_proz += proz;
				move(row / 2, x_temp);
				x_temp++;
				addch(tempA.at(i) | A_BLINK);
				i++;
				if (i == tempA.length())
				{
					DOP += 5;
					flag = 1;
					i = 0;

					if (level == 8)
					{
						break;
					}
					level++;
				}
			}
			else
			{
				DOP -= 1;
			}
		}
	} while (endTime < startTime + (DOP + SEK) * 1000);
	nodelay(stdscr, FALSE);
	dopusk (row, col, Lessen, endTime, startTime,sum_proz);
}



void Select_level(int slozh, int row, int col)
{
	int Lessen = 1;

	erase();
	printRamka(row, col);
		switch (slozh)
		{
		case 1:
		{
			Lessen = 1;
			level1("level1.txt", row, col, Lessen);
			break;
		}

		case 2:
		{
			Lessen = 2;
			level1("level2.txt", row, col, Lessen);
			break;
		}

		case 3:
		{
			Lessen = 3;
			level1("level3.txt", row, col, Lessen);
			break;
		}
		case 4:
			break;
		}
	
}
