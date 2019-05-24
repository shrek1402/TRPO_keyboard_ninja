#include "pch.h"

constexpr auto _VERSION = "Beta v1.0";
constexpr unsigned int _SEC = 1;


bool razmer()
{
	int col, row;
	getmaxyx(stdscr, row, col);
	if (row <  10) throw "Uvelich visotu okna";
	if (col < 40) throw "Uvelich shirinu okna";
	return true;
}