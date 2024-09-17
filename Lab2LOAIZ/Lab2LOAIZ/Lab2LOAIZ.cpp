#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <iostream>

using namespace std;

int main(void)
{
	setlocale(LC_ALL, "ru");
	setvbuf(stdin, NULL, _IONBF, 0);
	setvbuf(stdout, NULL, _IONBF, 0);

	clock_t start, end; // объявляем переменные для определения времени выполнения

	cout << "Выберите размер матриц:\n1 - 100\n2 - 200\n3 - 400\n4 - 1000\n5 - 2000\n6 - 4000\n7 - 10000\nВыбор: ";
	int nabor;
	cin >> nabor;
	int razm;
	switch (nabor)
	{
	case 1:
		razm = 100;
		break;
	case 2:
		razm = 200;
		break;
	case 3:
		razm = 400;
		break;
	case 4:
		razm = 1000;
		break;
	case 5:
		razm = 2000;
		break;
	case 6:
		razm = 4000;
		break;
	case 7:
		razm = 10000;
		break;
	}

	int** ptr_razm_a = new int* [razm];

	for (int i = 0; i < razm; i++)
	{
		ptr_razm_a[i] = new int[razm];
	}

	int** ptr_razm_b = new int* [razm];

	for (int i = 0; i < razm; i++)
	{
		ptr_razm_b[i] = new int[razm];
	}

	int** ptr_razm_c = new int* [razm];

	for (int i = 0; i < razm; i++)
	{
		ptr_razm_c[i] = new int[razm];
	}

	int i = 0, j = 0, r;
	//int a[200][200], b[200][200], c[200][200], elem_c;

	srand(time(NULL)); // инициализируем параметры генератора случайных чисел
	while (i < razm)
	{
		while (j < razm)
		{
			ptr_razm_a[i][j] = rand() % 100 + 1; // заполняем массив случайными числами
			j++;
		}
		i++;
	}
	srand(time(NULL)); // инициализируем параметры генератора случайных чисел
	i = 0; j = 0;
	while (i < razm)
	{
		while (j < razm)
		{
			ptr_razm_b[i][j] = rand() % 100 + 1; // заполняем массив случайными числами
			j++;
		}
		i++;
	}
	int elem_c;

	start = clock();

	for (i = 0; i < razm; i++)
	{
		for (j = 0; j < razm; j++)
		{
			elem_c = 0;
			for (r = 0; r < razm; r++)
			{
				elem_c = elem_c + ptr_razm_a[i][r] * ptr_razm_b[r][j];
				ptr_razm_c[i][j] = elem_c;
			}
		}
	}

	end = clock();

	double vremya;
	vremya = ((double)start / (double)end) / CLOCKS_PER_SEC;
	cout << "Время работы программы: " << vremya;

	for (int i = 0; i < razm; i++)
	{
		delete[]ptr_razm_c[i];
	}
	delete[]ptr_razm_c;

	for (int i = 0; i < razm; i++)
	{
		delete[]ptr_razm_b[i];
	}
	delete[]ptr_razm_b;

	for (int i = 0; i < razm; i++)
	{
		delete[]ptr_razm_a[i];
	}
	delete[]ptr_razm_a;

	return(0);
}


