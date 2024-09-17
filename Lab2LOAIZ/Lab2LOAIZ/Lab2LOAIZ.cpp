#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <iostream>

using namespace std;

void shell(int* items, int count)
{

	int i, j, gap, k;
	int x, a[5];

	a[0] = 9; a[1] = 5; a[2] = 3; a[3] = 2; a[4] = 1;

	for (k = 0; k < 5; k++) {
		gap = a[k];
		for (i = gap; i < count; ++i) {
			x = items[i];
			for (j = i - gap; (x < items[j]) && (j >= 0); j = j - gap)
				items[j + gap] = items[j];
			items[j + gap] = x;
		}
	}
}

void qs(int* items, int left, int right) //вызов функции: qs(items, 0, count-1);
{
	int i, j;
	int x, y;



	i = left; j = right;

	/* выбор компаранда */
	x = items[(left + right) / 2];

	do {
		while ((items[i] < x) && (i < right)) i++;
		while ((x < items[j]) && (j > left)) j--;

		if (i <= j) {
			y = items[i];
			items[i] = items[j];
			items[j] = y;
			i++; j--;
		}
	} while (i <= j);

	if (left < j) qs(items, left, j);
	if (i < right) qs(items, i, right);
}


int main()
{
	setlocale(LC_ALL, "ru");
	srand(time(NULL));

	clock_t start, end;

	const int SIZE = 100000;
	int mass[SIZE];

	for (int i = 0; i < SIZE; i++)
	{
		mass[i] = i;
	}

	start = clock();
	//qs(mass, 0, SIZE-1);
	//shell(mass, SIZE);
	end = clock();

	double vremya;
	vremya = ((double)start / (double)end) / CLOCKS_PER_SEC;

	cout << "\nВремя выполнения программы: " << vremya;

	return 0;
}