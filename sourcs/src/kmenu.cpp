#include "pch.h"

using namespace std;
constexpr auto _VERSION = "Release v3.1";
int _SEC = 5;

int printWelcomePanel(string _str, int row, int col)
{
    std::ifstream dataFile(_str);
    if (!dataFile)
        return 1;
    std::vector<std::string> vec;

    while (!dataFile.eof()) {
        std::string temp;
        std::getline(dataFile, temp);
        vec.push_back(temp);
    }

    for (long long unsigned int i = 0; i < vec.size(); i++) {
        mvprintw(
                row / 2 - vec.size() / 2 + 2 + i,
                col / 2 - vec.at(i).length() / 2,
                "%s",
                vec.at(i).c_str());
    }
    refresh();
    getch();
    dataFile.close();
    return 0;
}

long long unsigned int
printMenu(std::vector<std::string>* _vec, long long unsigned int punk)
{
    init_pair(1, COLOR_WHITE, COLOR_BLACK);
    attron(COLOR_PAIR(1));
    long long unsigned int swtch = 1;
    int key;
    int col, row;
    getmaxyx(stdscr, row, col);

    do {
        for (long long unsigned int i = 0; i < _vec->size(); i++) {
            move(row / 2 + i - 1, col / 2 - _vec->at(0).length() / 2);

            if (i == swtch) {
                for (long long unsigned int j = 0; j < _vec->at(i).length();
                     j++)
                    addch(_vec->at(i).at(j) | (COLOR_PAIR(4)));
            } else {
                printw("%s", _vec->at(i).c_str());
            }
        }

        if ((key = getch()) == KEY_UP) {
            if (swtch != 1)
                swtch--;
            else
                swtch = punk - 1;
        } else if (key == KEY_DOWN) {
            if (swtch != punk - 1)
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
    printRamka(row, col);
    std::vector<std::string> mStr = {"         Menu         ",
                                     "1. Speed mode         ",
                                     "2. Typing tutor       ",
                                     "3. Numerical simulator",
                                     "4. Exit               "};

    noecho();
    keypad(stdscr, TRUE);

    return printMenu(&mStr, mStr.size());
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

    mvaddstr(1, _col - 14, _VERSION);
    wrefresh(win1);
    wrefresh(win);
    return 0;
}

int complexity(int row, int col)
{
    printRamka(row, col);
    std::vector<std::string> mStr = {"Complexity ", // TODO eng
                                     "1. Eazy    ",
                                     "2. Normal  ",
                                     "3. Hard    ",
                                     "4. Settings",
                                     "5. Back    "};

    noecho();
    return printMenu(&mStr, mStr.size());
}

double reaction(int _SEC, int result)
{
    if (!result)
        return 0;

    return (double)_SEC / result;
}

int getYY(int row, int ySize)
{
    return (row - ySize - 5) / 2 + 4;
}

int getXX(int col, int xSize)
{
    return (col - xSize) / 2; // TODO /////////////////////////////////////
}

void resultTabl(int result, int popitki)
{
    attron(COLOR_PAIR(1));
    int row, col;
    getmaxyx(stdscr, row, col);
    printRamka(row, col);
    int ySize = 9, xSize = col - (row - ySize + 3 + 2), yy = getYY(row, ySize),
        xx = getXX(col, xSize);

    if ((col - xSize) % 2 != 0)
        xSize++;
    if ((row - ySize) % 2 == 0)
        ySize++;

    WINDOW* win = newwin(ySize, xSize, yy, xx);

    if (result) {
        attron(COLOR_PAIR(2));
        mvprintw(yy += 3, xx + xSize / 2 - 6, "PERFECT! :)");
    } else {
        attron(COLOR_PAIR(3));
        mvprintw(yy += 3, xx + xSize / 2 - 6, "BADLY!   :(");
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
    time_t startTime = time(NULL);
    time_t endTime = startTime;
    startTime += _SEC;
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
            endTime = time(NULL);
            mvprintw(1, 5, "%.2f ms", difftime(startTime, endTime));
            mvprintw(1, 1, "%d", result);
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

                    if (endTime < startTime + _SEC) {
                        result++;
                    }
                }

                refresh();
            }
            attron(COLOR_PAIR(1));
        }
    } while (difftime(endTime, startTime));

    nodelay(stdscr, FALSE);
    resultTabl(result, popitki);
}

void speedEz()
{
    int row, col;
    getmaxyx(stdscr, row, col);
    unsigned int result = 0;
    time_t startTime = time(NULL);
    time_t endTime = startTime;
    startTime += _SEC;

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
                mvprintw(y, x, "%c", tempA);
                flag = 0;
                popitki++;
            }

            endTime = time(NULL);
            mvprintw(1, 5, "%.2f s", difftime(startTime, endTime));
            mvprintw(1, 1, "%d", result);
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
    } while (difftime(endTime, startTime));

    nodelay(stdscr, FALSE);
    resultTabl(result, popitki);
}

void settings()
{
    int col, row;
    getmaxyx(stdscr, row, col);
    printRamka(row, col);
    mvprintw(row / 2 + 2, col / 2 - 5, "Time : ");
    echo();
    scanw("%d", &_SEC);
    noecho();
    keypad(stdscr, TRUE);

    return;
}

void speedMode(int complexity, int row, int col)
{
    printRamka(row, col);

    switch (complexity) {
    case 1:
        speedEz();
        break;
    case 2:
        speedNormal("data/WordsENG.txt", row, col);
        break;
    case 3:
        speedNormal("data/ProposalENG.txt", row, col);
        break;
    case 4:
        settings();
        break;
    case 5:
        break;
    }
}