#include "pch.h"

int Num_Menu(int row, int col)
{
	int punk=4;
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
	return printMenu(&N_Menu,punk);
}

void Select_item (int item, int row, int col) {
    erase();
	printRamka(row, col);
	int A[3]={0, 0 ,0};
	switch(item){
		case 1: {
			SpeedNum(row, col, A);
			ResultNum (row, col, A);
			break;
		}
		case 2: {
			Solving(row, col, A);
			ResultNum (row, col, A);
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

int* SpeedNum(int row, int col, int* A) {
	srand(time(0));
	nodelay(stdscr, TRUE);
	unsigned int StartTime = clock(), EndTime = clock();
	int i=0, k=0, time=30, flag=1, size, ch;
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
		move(5, col/2-6);
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
				A[0]++; //подсчет чисел
			}
		}
		else
		{
			if (str2[i] == ch)
			{
				move(row / 2, col / 2 + i); //перемещаемся в строке const + i (где i - номер текущего символа)
				addch(str2.at(i) | A_STANDOUT); //выделение правильно введеного символа
				i++;
				A[1]++; //подсчет символов
				if (i == size) //достижение конца строки
				{
					flag = 1; //"включение" новой строки 
					i = 0; //обнуляем счетчик для новой строки
				}
			}
			else A[2]++; //ошибки ввода
		}
	} while (EndTime < StartTime + time * 1000);
	nodelay(stdscr, FALSE);
return A;
}

int ResultNum (int row, int col, int* A) {
	erase();
	printRamka(row, col);
	attron (A_BOLD);

	float result0, result1;
	result0=(double)A[0]/(double)30;
	result1=(double)A[1]/(double)30;
	move(row / 2 - 10, col / 2-5);
	printw("Your results:\n");

	move(row / 2 - 5, 25);
	printw("Your speed in simvols = %.2f per second", result1);
	if ((double)A[1]/(double)30 > 1) {
	printw("	[GOOD]");
	}
	else printw("	[NOT GOOD] You should train more!");
	
	move(row / 2, 25);
	printw("Your speed in numbers = %.2f per second", result0);
	if ((double)A[0]/(double)30 > 1) {
	printw("	[GOOD]");
	}
	else printw("	[NOT GOOD] You should train more!");

	move(row / 2 + 5, 25);
	printw("Your errors = %d", A[2]);
	if (A[2] < 5) {
	printw("	[GOOD]");
	}
	else printw("	[NOT GOOD] You should train more!");
	getch();
return 0;
}

int* Solving (int row, int col, int* A) {
	srand(time(0));
	unsigned int StartTime = clock(), EndTime = clock();
	int i=0, k=0, time=30, flag=1, ch;
	ifstream equation("Equation.txt");
	ifstream equationA("EquationAnswers.txt");
	string array1[100], array2[100];
	string str1, str2;
	erase();
	printRamka(row, col);
	while (!equation.eof()){		//заполняем массив уравнениями из файла
		getline(equation, str1);
		array1[i]=str1;
		i++;
	}
	str1="";
		while (!equationA.eof()){		//заполняем массив ответами из файла
		getline(equationA, str1);
		array2[i]=str1;
		i++;
	}
	do {
		move(1, 2);				//таймер
		printw("Time left: ");
		EndTime = clock();
		move(1, 13);
		printw("%d sec", (time * 1000 - (EndTime - StartTime))/1000);
		if (((StartTime + time * 1000)-EndTime)<16000)
		{
		move(5, col/2-6);
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
				k = rand()%34;			//выбираем случайную строку из массива
				str2 = array1[k];
				move(row / 2, col / 2);
				printw("%s", str2.c_str());
				flag = 0;
				A[0]++; //подсчет кол-ва уравнений
			}
		}
		else
		{
			move(row/2+10, col/2+10);
			printw("Input your answer and print 'Enter' ");
			move(row/2+15, col/2+15);
			printw("Answer= ");
			cin >> str1;
			if (str1==array2[k])
			{
				flag=1;
				A[1]++;
			}
			else A[2]++; //ошибки ввода
		}
	} while (EndTime < StartTime + time * 1000);
return A;
}