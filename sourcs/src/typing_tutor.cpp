#include "pch.h"

#define Correct_green 1
#define Basic_style 2
#define Wrong_red 3

const unsigned int SEK = 60;
int menu_lesson(int row, int col)
{
    int punk = 7;
    erase();
    printRamka(row, col);
    std::vector<std::string> mStr = {"Learning touch typing",
                                     "Lesson 1",
                                     "Lesson 2",
                                     "Lesson 3",
                                     "Lesson 4",
                                     "Lesson 5",
                                     "Lesson 6",
                                     "Backward"

    };

    noecho();
    keypad(stdscr, TRUE);
    return printMenu(&mStr, punk);
}

void resultat(
        int row,
        int col,
        int Lessen,
        unsigned int endTime,
        unsigned int startTime,
        double sum_proz,
        int error)
{
    erase();
    start_color();
    init_pair(Correct_green, COLOR_GREEN, COLOR_BLACK);
    init_pair(Basic_style, COLOR_WHITE, COLOR_BLACK);
    init_pair(Wrong_red, COLOR_RED, COLOR_BLACK);
    attron(COLOR_PAIR(Basic_style));
    printRamka(row, col);
    int size_x, size_y, xx, yy;
    size_x = 80;
    size_y = 20;
    xx = 20;
    yy = 15;
    WINDOW* win5 = newwin(size_y, size_x, yy, xx);
    if (sum_proz < 100) {
        attron(COLOR_PAIR(Wrong_red));
        move((row - 4) / 2 - 2, (col - 26) / 2);
        printw("Time's up, try again!");
    } else {
        attron(COLOR_PAIR(Correct_green));
        move((row - 4) / 2 - 2, (col - 26) / 2);
        printw("Well done keep learning!");
    }

    move(1, (col - 4) / 2);
    printw("Lessen %d", Lessen);
    move((row - 4) / 2, (col - 26) / 2);
    printw("Execution time %d ms", endTime - startTime);
    move((row - 4) / 2 + 2, (col - 26) / 2);
    printw("You passed %3.2f percent of the lesson", sum_proz);
    move((row - 4) / 2 + 4, (col - 26) / 2);
    printw("Incorrectly entered letters %d", error);
    box(win5, 0, 0);
    wrefresh(win5);
    getch();
    attron(COLOR_PAIR(Basic_style));
}

void Lessen1(std::string _dataFile, int row, int col, int Lessen)
{
    start_color();
    init_pair(Correct_green, COLOR_GREEN, COLOR_BLACK);
    init_pair(Basic_style, COLOR_WHITE, COLOR_BLACK);
    init_pair(Wrong_red, COLOR_RED, COLOR_BLACK);

    std::ifstream dataFile(_dataFile);
    std::vector<std::string> vec;
    double max_leg = 0.0;
    while (!dataFile.eof()) {
        std::string temp;
        std::getline(dataFile, temp);
        max_leg += temp.length();
        vec.push_back(temp);
    }

    unsigned int startTime = clock();
    unsigned int endTime = startTime, DOP = 0;
    nodelay(stdscr, TRUE);
    int ch;
    int temp, error = 0;
    long long unsigned int i = 0;
    std::string tempA;
    bool flag = 1;
    int x_temp = 0, level = 1;
    double proz = 0, sum_proz = 0.0;

    proz = 100 / max_leg;

    do {
        attron(COLOR_PAIR(Basic_style));
        if ((ch = getch()) == ERR) {
            if (flag) {
                erase();
                printRamka(row, col);
                tempA = vec.at(level - 1);
                move(row / 2, (col - tempA.length()) / 2);
                printw("%s", tempA.c_str());
                x_temp = (col - tempA.length()) / 2;
                flag = 0;
            }
            char a = '%';
            attron(A_BOLD);
            move(10, (col - 12) / 2);
            printw("%3.2f %c", sum_proz, a);
            endTime = clock();
            move(1, 10);
            printw("%d ms", (DOP + SEK) * 1000 - (endTime - startTime));
            move(1, 1);
            printw("Lessen %d", Lessen);
            attroff(A_BOLD);
        } else {
            temp = ch;
            flag = 0;

            if (tempA[i] == temp) {
                sum_proz += proz;

                move(row / 2, x_temp);

                attron(COLOR_PAIR(Correct_green));
                addch(tempA.at(i));
                attroff(COLOR_PAIR(Correct_green));

                x_temp++;
                i++;
                if (i == tempA.length()) {
                    DOP += 3;
                    flag = 1;
                    i = 0;

                    if (level == 8) {
                        break;
                    }
                    level++;
                }
            } else {
                DOP -= 1;
                error++;
            }
        }
    } while (endTime < startTime + (DOP + SEK) * 1000);
    nodelay(stdscr, FALSE);
    resultat(row, col, Lessen, endTime, startTime, sum_proz, error);
}

void Select_level(int temp, int row, int col)
{
    int Lessen = 1;

    erase();
    printRamka(row, col);
    switch (temp) {
    case 1: {
        Lessen = 1;
        Lessen1("level1.txt", row, col, Lessen);
        break;
    }

    case 2: {
        Lessen = 2;
        Lessen1("level2.txt", row, col, Lessen);
        break;
    }

    case 3: {
        Lessen = 3;
        Lessen1("level3.txt", row, col, Lessen);
        break;
    }
    case 4: {
        Lessen = 4;
        Lessen1("level4.txt", row, col, Lessen);
        break;
    }
    case 5: {
        Lessen = 5;
        Lessen1("level5.txt", row, col, Lessen);
        break;
    }
    case 6: {
        Lessen = 6;
        Lessen1("level6.txt", row, col, Lessen);
        break;
    }
    }
}
