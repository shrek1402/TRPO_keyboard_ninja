#include "pch.h"

int Num_Menu(int row, int col)
{
    int punk = 4;
    erase();
    printRamka(row, col);
    std::vector<std::string> N_Menu = {"Exercises with numbers:",
                                       "1. Speed Number     ",
                                       "2. Solving equations",
                                       "3. Calculator       ",
                                       "4. Back to main menu"};

    noecho();
    keypad(stdscr, TRUE);
    return printMenu(&N_Menu, punk);
}

void Select_item(int item, int row, int col)
{
    erase();
    printRamka(row, col);
    int A[3] = {0, 0, 0};
    switch (item) {
    case 1: {
        SpeedNum(row, col, A);
        ResultNum(row, col, A, 0);
        break;
    }
    case 2: {
        Solving(row, col, A);
        ResultNum(row, col, A, 1);
        break;
    }
    case 3: {
        Calculator(row, col, A);
        ResultNum(row, col, A, 2);
        break;
    }
    case 4: {
        break;
    }
    }
}

int GetString(string file, string array[100])
{
    ifstream File(file);
    if (!(File.is_open())) {
        return 0;
    }
    string str;
    int i = 0;
    while (!File.eof()) { //заполняем массив строками из файла
        getline(File, str);
        array[i] = str;
        i++;
    }
    return 1;
}
int* SpeedNum(int row, int col, int* A)
{
    srand(time(0));
    nodelay(stdscr, TRUE);
    start_color();
    init_pair(1, COLOR_GREEN, COLOR_BLACK);
    init_pair(2, COLOR_RED, COLOR_BLACK);
    init_pair(3, COLOR_WHITE, COLOR_BLACK);
    time_t StartTime = time(NULL);
    time_t EndTime = StartTime;
    int i = 0, k = 0, Timer = 30, flag = 1, size, ch;
    string str1, str2;
    string array[100];
    GetString("data/Numbers.txt", array);
    erase();
    printRamka(row, col);
    do {
        Time(row, col, 30, EndTime, StartTime);
        if ((ch = getch()) == ERR) {
            if (flag) {
                erase();              //для очищения от
                printRamka(row, col); //выделения с прошлой итерации
                k = rand() % 100; //выбираем случайную строку из массива
                str2 = array[k];
                size = str2.length(); //получение длины очередой строки
                move(row / 2, col / 2);
                printw("%s", str2.c_str());
                flag = 0;
                A[0]++; //подсчет чисел
            }
        } else {
            if (str2[i] == ch) {
                move(row / 2, col / 2 + i); //перемещаемся в строке const + i
                                            //(где i - номер текущего символа)
                attron(COLOR_PAIR(1));
                addch(str2.at(i)); //выделение правильно введеного символа
                attron(COLOR_PAIR(3));
                i++;
                A[1]++;        //подсчет символов
                if (i == size) //достижение конца строки
                {
                    flag = 1; //"включение" новой строки
                    i = 0; //обнуляем счетчик для новой строки
                }
            } else {
                move(row / 2, col / 2 + i);
                attron(COLOR_PAIR(2)); //выделение неправильно введеного символа
                addch(str2.at(i));
                attron(COLOR_PAIR(3));
                i++;
                A[2]++;
                if (i == size) //достижение конца строки
                {
                    flag = 1; //"включение" новой строки
                    i = 0; //обнуляем счетчик для новой строки
                }
            } //ошибки ввода
        }
        EndTime = time(NULL);
    } while (difftime(EndTime, (StartTime + Timer)));
    move(1, 13);
    printw("0 sec ");
    TimeLeft(row, col);
    nodelay(stdscr, FALSE);
    return A;
}

int CalcResult(
        int A0,
        int A1,
        double& result0,
        double& result1,
        int flag,
        int test_flag)
{
    switch (flag) {
    case 0: {
        result0 = (double)A0 / (double)30;
        result1 = (double)A1 / (double)30;
        break;
    }
    case 1: {
        result0 = (double)A0 / (double)A1;
        result1 = (double)A0 / (double)60;
        break;
    }
    case 2: {
        result0 = (double)A0 / (double)30;
        result1 = (double)(A1) / (double)(A0);
        break;
    }
    }
    if (test_flag == 0)
        return result0;
    else
        return result1;
    return -1;
}
int ResultNum(int row, int col, int* A, int flag)
{
    double result0 = 0, result1 = 0;
    erase();
    printRamka(row, col);
    attron(A_BOLD);
    move(row / 2 - row / 4, col / 2 - 5);
    printw("Your results:");

    switch (flag) {
    case 0: {
        CalcResult(A[0], A[1], result0, result1, 0, 0);
        move(row / 2 - row / 4 + 2, 3);
        printw("Your speed in simvols = %.2f per second", result1);
        if (result1 > 1) {
            printw("   [GOOD]");
        } else
            printw("   [NOT GOOD] You should train more!");

        move(row / 2 - row / 4 + 4, 3);
        printw("Your speed in numbers = %.2f per second", result0);
        if (result0 > 1) {
            printw("   [GOOD]");
        } else
            printw("   [NOT GOOD] You should train more!");

        move(row / 2 - row / 4 + 6, 3);
        printw("Your errors = %d", A[2]);
        if (A[2] < 5) {
            printw("   [GOOD]");
        } else
            printw("   [NOT GOOD] You should train more!");
        move(row / 2 + row / 3, col / 2 - 13);
        printw("Press any key to continue...");
        break;
    }
    case 1: {
        CalcResult(A[0], A[1], result0, result1, 1, 0);
        move(row / 2 - row / 4 + 2, 3);
        printw("Total equations: %d", A[0]);

        move(row / 2 - row / 4 + 4, 3);
        printw("Correct solved equations: %d ", A[1]);
        if (result0 > 0.7) {
            printw("   [GOOD]");
        } else
            printw("   [NOT GOOD] You should train more!");

        move(row / 2 - row / 4 + 6, 3);
        printw("Your errors = %d", A[2]);
        if (A[2] < 4) {
            printw("   [GOOD]");
        } else
            printw("   [NOT GOOD] You should train more!");

        move(row / 2 - row / 4 + 8, 3);
        printw("Your solving speed = %.2f", result1);
        if (result1 > 0.2) {
            printw("	[GOOD]");
        } else
            printw("   [NOT GOOD] You should train more!");
        move(row / 2 + row / 3, col / 2 - 13);
        printw("Press any key to continue...");
        break;
    }
    case 2: {
        CalcResult(A[0], A[1], result0, result1, 2, 0);
        move(row / 2 - row / 4 + 2, 3);
        printw("Your speed in simvols = %.2f per second", result0);
        if (result0 > 1) {
            printw("   [GOOD]");
        } else
            printw("   [NOT GOOD] You should train more!");

        move(row / 2 - row / 4 + 4, 3);
        printw("Correct simvols = %d from %d (%.0f percents)",
               A[1],
               A[0],
               result1 * 100);
        if (result1 > 0.75) {
            printw("   [GOOD]");
        } else
            printw("   [NOT GOOD] You should train more!");

        move(row / 2 - row / 4 + 6, 3);
        printw("Uncorrect simvols = %d", A[2]);
        if (A[2] < 5) {
            printw("   [GOOD]");
        } else
            printw("   [NOT GOOD] You should train more!");
        move(row / 2 + row / 3, col / 2 - 13);
        printw("Press any key to continue...");
        break;
    }
    }
    getch();
    return 0;
}

int* Solving(int row, int col, int* A)
{
    nodelay(stdscr, TRUE); //для выключения паузы
    srand(time(0));
    start_color();
    init_pair(2, COLOR_RED, COLOR_BLACK);
    init_pair(3, COLOR_WHITE, COLOR_BLACK);
    time_t StartTime = time(NULL);
    time_t EndTime = StartTime;
    int i = 0, k = 0, Timer = 60, flag = 1, ch, size, flagik = 0;
    string array1[100], array2[100];
    string str1, str2, str3 = "", temp;
    erase();
    printRamka(row, col);
    GetString("data/Equation.txt", array1);
    GetString("data/EquationAnswers.txt", array2);
    do {
        Time(row, col, 60, EndTime, StartTime);

        if ((ch = getch()) == ERR) {
            if (flag) {
                erase();              //для очищения от
                printRamka(row, col); //выделения с прошлой итерации
                k = rand() % 33; //выбираем случайную строку из массива
                str2 = array1[k];
                size = str2.length();
                if (size % 2 == 1) {
                    size++;
                    flagik = 1;
                } else
                    flagik = 0;
                str1 = array2[k];
                move(row / 2, col / 2 - size / 2 + flagik);
                printw("%s", str2.c_str());
                move(row / 2 + 5, col / 2 - 16);
                printw("Input your answer and print 'Enter' ");
                flag = 0;
                str3 = "";
                i = 0;
                A[0]++; //подсчет кол-ва уравнений
            }
        } else {
            if (ch != '\n') {
                if (str3.length() < 6) {
                    move(row / 2, col / 2 + size / 2 + i);
                    temp = ch;
                    str3 += temp;
                    addch(str3.at(i) | A_STANDOUT);
                    i++;
                }
            } else if (str3 == array2[k]) {
                A[1]++; //правильный ввод
                flag = 1;
            } else {
                A[2]++; //ошибки ввода
                flag = 1;
            }
        }
        EndTime = time(NULL);
    } while (difftime(EndTime, (StartTime + Timer)));
    move(1, 13);
    printw("0 sec ");
    TimeLeft(row, col);
    nodelay(stdscr, FALSE);
    return A;
}

int* Calculator(int row, int col, int* A)
{
    nodelay(stdscr, TRUE); //для выключения паузы
    start_color();
    init_pair(1, COLOR_GREEN, COLOR_BLACK);
    init_pair(2, COLOR_RED, COLOR_BLACK);
    init_pair(3, COLOR_WHITE, COLOR_BLACK);
    srand(time(0));
    time_t StartTime = time(NULL);
    time_t EndTime = StartTime;
    int i = 0, k = 0, Timer = 30, flag = 1, ch, size;
    string array1[100];
    string str1, str2, temp;
    GetString("data/Calculator.txt", array1);
    erase();
    printRamka(row, col);

    do {
        Time(row, col, 30, EndTime, StartTime);
        if ((ch = getch()) == ERR) {
            if (flag) {
                erase();              //для очищения от
                printRamka(row, col); //выделения с прошлой итерации
                k = rand() % 51; //выбираем случайную строку из массива
                str2 = array1[k];
                size = str2.length();
                move(row / 2, col / 2 - size / 2 + 1);
                printw("%s", str2.c_str());
                move(row / 2 - 5, col / 2 - 8);
                printw("Enter this equation!");
                flag = 0;
                i = 0;
            }
        } else {
            if (str2[i] == ch || (str2[i] == 47 && ch == 458)
                || (str2[i] == 42 && ch == 463) || (str2[i] == 43 && ch == 465)
                || (str2[i] == 45 && ch == 464)) {
                move(row / 2,
                     col / 2 - size / 2 + 1
                             + i); //перемещаемся в строке const + i
                                   //(где i - номер текущего символа)
                attron(COLOR_PAIR(1));
                addch(str2.at(i)); //выделение правильно введеного символа
                attron(COLOR_PAIR(3));
                i++;
                A[1]++; //подсчет верных символов
                A[0]++; //подсчет общего кол-ва символов
                if (i == size) //достижение конца строки
                {
                    flag = 1; //"включение" новой строки
                    i = 0; //обнуляем счетчик для новой строки
                }
            } else {
                move(row / 2, col / 2 - size / 2 + 1 + i);
                attron(COLOR_PAIR(2)); //выделение неправильно введеного символа
                addch(str2.at(i));
                attron(COLOR_PAIR(3));
                i++;
                A[2]++; //ошибки ввода
                A[0]++; //подсчет общего кол-ва символов
                if (i == size) //достижение конца строки
                {
                    flag = 1; //"включение" новой строки
                    i = 0; //обнуляем счетчик для новой строки
                }
            }
        }
        EndTime = time(NULL);
    } while (difftime(EndTime, (StartTime + Timer)));
    move(1, 13);
    printw("0 sec ");
    TimeLeft(row, col);
    nodelay(stdscr, FALSE);
    return A;
}

int Time(int row, int col, int Timer, int EndTime, int StartTime)
{
    if (((StartTime + Timer) - EndTime) < 16) {
        attron(COLOR_PAIR(2));
        move(1, 2);
        printw("Time left: ");
        EndTime = time(NULL);
        move(1, 13);
        printw("%d sec ", (Timer - (EndTime - StartTime)));
        attron(COLOR_PAIR(3));
        move(row / 2 - row / 4, col / 2 - 7);
        attron(A_BOLD);
        printw("Let's! Pull baker!");
        attron(A_NORMAL);
    } else {
        attron(COLOR_PAIR(3));
        move(1, 2);
        printw("Time left: ");
        EndTime = time(NULL);
        move(1, 13);
        printw("%.2d sec", (Timer - (EndTime - StartTime)));
    }
    return (EndTime - StartTime);
}
void TimeLeft(int row, int col)
{
    int ch, Timer = 3;
    time_t StartTime = time(NULL);
    time_t EndTime = StartTime;
    do {
        if ((ch = getch()) == ERR) {
            move(row / 2 + row / 3, col / 2 - 5);
            printw("Time is left.");
            move(row / 2 + row / 3 + 1, col / 2 - 8);
            printw("Your result into %d", (Timer - (EndTime - StartTime)));
            EndTime = time(NULL);
        }
    } while (EndTime < StartTime + Timer);
}