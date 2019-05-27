#include "pch.h"

int Num_Menu(int row, int col)
{
	erase();
	printRamka(row, col);
	std::vector<std::string> N_Menu = {
		"Exercises with numbers:",
		"1. Speed Number",
		"2. Solving equations",
	 	"3. Calculator",
		"4. Back to main menu"
	};

	noecho();
	keypad(stdscr, TRUE);
	return printMenu(N_Menu);
}

void Select_item (int item, int row, int col) {
    erase();
	printRamka(row, col);

	switch(item){
		case 1: {
			SpeedNum(row, col);
			break;
		}
		case 2: {
		//	Solving();
			break;
		}
		case 3: {
		//	Calculator();
			break;
		}
		case 4: {
			break;
		}
	}
}

int SpeedNum(int row, int col) {
	srand(time(0));
	nodelay(stdscr, TRUE);
	unsigned int StartTime = clock(), EndTime = clock(), otvet=0;
	int ch;
	int i=0, k=0, time=30, flag=1, size;
	ifstream Numbers("Numbers.txt");
	string array[100];
	string str1, str2;
	erase();
	printRamka(row, col);
	while (!Numbers.eof()){		//заполняем массив строками из файла
		getline(Numbers, str1);
		array[i]=str1;
		i++;
	}
	i=0;
	do {
		move(1, 2);				//таймер
		printw("Time left: ");
		EndTime = clock();
		move(1, 13);
		printw("%d sec", (time * 1000 - (EndTime - StartTime))/1000);
		if (((StartTime + time * 1000)-EndTime)<16000)
		{
		move(5, col/2-9);
		attron (A_BOLD);
		printw("Let's! Pull baker!");
		attron (A_NORMAL);
		}
		if ((ch = getch()) == ERR)
		{
			if (flag)
			{
				erase();				//для очищения от 
				printRamka(row, col);	//выделения с прошлой итерации
				k = rand()%100;			//выбираем случайную строку из массива
				str2 = array[k];
				size=str2.length();		//получение длины очередой строки
				move(row / 2, col / 2);
				printw("%s", str2.c_str());
				flag = 0;
			}
		}
		else
		{
			if (str2[i] == ch)
			{
				move(row / 2, col / 2 + i); //перемещаемся в строке const + i (где i - номер текущего символа)
				addch(str2.at(i) | A_STANDOUT); //выделение правильно введеного символа
				i++;
				otvet++;
				if (i == size) //достижение конца строки
				{
					flag = 1; //"включение" новой строки 
					i = 0; //обнуляем счетчик для новой строки
				}
			}
		}
	} while (EndTime < StartTime + time * 1000);
	nodelay(stdscr, FALSE);
return otvet;
}