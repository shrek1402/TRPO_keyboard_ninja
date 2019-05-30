#ifndef PCH_H
#define PCH_H
#define PDC_DLL_BUILD

#ifdef _WIN32
#include <curses.h>
#else
#include <ncurses.h>
#endif

	#include <ctime>
	#include <vector>
	#include <string>
	#include <fstream>
	#include <iostream>
	#include <stdlib.h>
	#include <string>
	#include <unistd.h>
	#include <cmath>
	#include <sstream>
	#include <math.h>

	using namespace std;

	bool razmer();
	void printWelcomePanel(std::string _str, int row, int col);
	int mainMenu(int row, int col);
	int printRamka(int _row, int _col);
	int slozhnost(int row, int col);
	void speedMode(int slozh, int row, int col);
	void speedNormal(std::string _dataFile, int row, int col);
	long long unsigned int printMenu(std::vector <std::string>* _vec, long long unsigned int punk);
	void Select_level(int slozh, int row, int col);
	int level(int row, int col);
	int Num_Menu(int row, int col);
	void Select_item (int item, int row, int col);
	int* SpeedNum(int row, int col, int* A);
	int ResultNum (int row, int col, int* A, int flag);
	int* Solving (int row, int col, int* A);
	int* Calculator (int row, int col, int* A);
	void Time (int row, int col, int time, int EndTime, int StartTime);
	void TimeLeft (int row, int col);
#endif