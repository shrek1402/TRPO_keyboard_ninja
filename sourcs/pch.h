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
#include <string.h>
#include <unistd.h>

bool razmer();

extern int col, row;