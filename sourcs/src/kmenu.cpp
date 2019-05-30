#include "pch.h"

using namespace std;
constexpr auto _VERSION = "Beta v1.0";
constexpr unsigned int _SEC = 5;

void printWelcomePanel(string _str, int row, int col)
{
    keypad(stdscr, 1);
    ifstream myTextFile;
    myTextFile.open(_str);
    if (!myTextFile.is_open())
        return;

    mvprintw(row / 2, col / 2, "Hello");
    refresh();
    getch();
    myTextFile.close();
}

long long unsigned int
printMenu(std::vector<std::string>* _vec, long long unsigned int punk)
{
    long long unsigned int swtch = 1;
    int key;
    int col, row;
    getmaxyx(stdscr, row, col);

    do {
        for (long long unsigned int i = 0; i < _vec->size(); i++) {
            move(row / 2 + i, col / 2 - _vec->at(0).length() / 2);

            if (i == swtch) {
                for (long long unsigned int j = 0; j < _vec->at(i).length();
                     j++)
                    addch(_vec->at(i).at(j) | A_BLINK);
            } else {
                printw("%s", _vec->at(i).c_str());
            }
        }

        if ((key = getch()) == KEY_UP) {
            if (swtch != 1)
                swtch--;
            else
                swtch = punk;
        } else if (key == KEY_DOWN) {
            if (swtch != punk)
                swtch++;
            else
                swtch = 1;
        }
        refresh();
    } while (key != '\n');

    return swtch;
}

int mainMenu(int row, int col)
{
    int punk = 4;
    printRamka(row, col);
    std::vector<std::string> mStr = {"    Menu          ",
                                     "1. Speed mode     ",
                                     "2. typing tutor   ",
                                     "3. Numerical Simulator",
                                     "4. Exit           "};

    noecho();
    keypad(stdscr, TRUE);

    return printMenu(&mStr, punk);
}

int printRamka(int _row, int _col)
{
    erase();
    curs_set(0);
    refresh();
    WINDOW* win = newwin(3, _col, 0, 0);
    box(win, 0, 0);

    WINDOW* win1 = newwin(_row - 3, _col, 3, 0);
    box(win1, 0, 0);

    mvaddstr(1, _col - 10, _VERSION);
    wrefresh(win1);
    wrefresh(win);
    return 0;
}

int slozhnost(int row, int col)
{
    int punk = 4;
    printRamka(row, col);
    std::vector<std::string> mStr = {"Complexity", // TODO eng
                                     "1. Eazy   ",
                                     "2. Normal ",
                                     "3. Hard   ",
                                     "4. Back   "};

    noecho();
    return printMenu(&mStr, punk);
}
double reaction(int _SEC, int result)
{
    if (!result)
        return 0;

    return (double)_SEC / result;
}

void resultTabl(int result, int popitki)
{
    attron(COLOR_PAIR(1));
    int row, col;
    getmaxyx(stdscr, row, col);
    printRamka(row, col);
    int ySize = 9, xSize = col - (row - ySize + 3 + 2),
        yy = (row - ySize - 5) / 2 + 4, // TEST
            xx = (col - xSize) / 2;     // TEST TOO

    if ((col - xSize) % 2 != 0)
        xSize++;
    if ((row - ySize) % 2 == 0)
        ySize++;

    WINDOW* win = newwin(ySize, xSize, yy, xx);
    // TODO add: time, % ...
    if (result) {
        attron(COLOR_PAIR(2));
        mvprintw(yy += 3, xx + xSize / 2 - 6, "MOLODEC! :)");
    } else {
        attron(COLOR_PAIR(3));
        mvprintw(yy += 3, xx + xSize / 2 - 6, "NE MOLODEC! :(");
    }

    mvprintw(++yy, xx + xSize / 2 - 6, "Result: %d", result);
    mvprintw(
            ++yy, xx + xSize / 2 - 6, "Reaction: %.2f", reaction(_SEC, result));
    attron(COLOR_PAIR(1));

    box(win, 0, 0);
    wrefresh(win);
    getch();
}

void speedNormal(string _dataFile, int row, int col)
{
    std::ifstream dataFile(_dataFile);
    std::vector<std::string> vec;

    while (!dataFile.eof()) {
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
    int x, y, x_temp;
    int popitki = 0;
    do {
        if ((ch = getch()) == ERR) {
            if (flag) {
                tempA = vec.at(rand() % vec.size());
                x = (rand() % (col - tempA.length() - 1) + 1);
                y = (rand() % (row - 5)) + 4;
                printRamka(row, col);
                move(y, x);
                printw("%s", tempA.c_str());
                flag = 0;
                popitki++;
            }
            attron(COLOR_PAIR(1));
            endTime = clock();
            move(1, 5);
            printw("%d ms", endTime - startTime);
            move(1, 1);
            printw("%d", result);
        } else {
            attron(COLOR_PAIR(2));
            temp = ch;
            flag = 0;
            if (ch == 27)
                break;
            if ((int)tempA[i] != temp || i == 0) {
                if (tempA[i] != temp) {
                    i = 0;
                    flag = 1;
                } else {
                    x_temp = x;
                    move(y, x_temp++);
                    addch(tempA.at(i));
                    i++;
                }

                refresh();
            } else {
                move(y, x_temp++);
                addch(tempA.at(i));
                i++;

                if (i == tempA.length()) {
                    flag = 1;
                    i = 0;

                    if (endTime < startTime + _SEC * 1000) {
                        result++;
                    }
                }

                refresh();
            }
            attron(COLOR_PAIR(1));
        }
    } while (endTime < startTime + _SEC * 1000);

    nodelay(stdscr, FALSE);
    resultTabl(result, popitki);
}

void speedEz()
{
    int row, col;
    getmaxyx(stdscr, row, col);
    unsigned int result = 0;
    unsigned int startTime = clock();
    unsigned int endTime = startTime;

    nodelay(stdscr, TRUE);
    int ch;
    int temp;
    bool flag = 1;
    int x, y;
    int popitki = 0;
    char tempA;

    do {
        if ((ch = getch()) == ERR) {
            if (flag) {
                tempA = rand() % 26 + 0x61;
                x = (rand() % (col - 1) + 1);
                y = (rand() % (row - 5)) + 4;
                printRamka(row, col);
                move(y, x);
                printw("%c", tempA);
                flag = 0;
                popitki++;
            }

            endTime = clock();
            move(1, 5);
            printw("%d ms", endTime - startTime);
            move(1, 1);
            printw("%d", result);
        } else {
            temp = ch;
            flag = 0;
            if (ch == 27)
                break;
            if ((int)tempA != temp) {
                flag = 1;
            } else {
                flag = 1;
                result++;
            }
            refresh();
        }
    } while (endTime < startTime + _SEC * 1000);

    nodelay(stdscr, FALSE);
    resultTabl(result, popitki);
}

void speedMode(int slozh, int row, int col)
{
    printRamka(row, col);

    switch (slozh) {
    case 1:
        speedEz();
        break;
    case 2:
        speedNormal("WordsENG.txt", row, col);
        break;
    case 3:
        speedNormal("ProposalENG.txt", row, col);
        break;
    case 4:
        break;
    }
}