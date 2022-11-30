#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include"sort.h"

#define MaxSize 10000
#define MinSize 1
#define MaxElement 100000
#define MinElement -100000

void choiseFunction(int* choise, int variant)
{
	while (scanf_s("%d", choise) != 1 || *choise < 0 || *choise>1 || getchar() != '\n')
	{
		rewind(stdin);
		printf("Error\n");
		switch (variant)
		{
		case 1:
			printf("If you want random input 1. If you want input masive by hands input 0.\n");
			break;

		case 2:
			printf("Do you want worse variant?(Yes-1,No-0):");
			break;
		}
	}

}

void inputChekerSize(int* n)
{
	while (scanf_s("%d", n) != 1 || *n > MaxSize || *n < MinSize || getchar() != '\n')
	{
		rewind(stdin);
		printf("Error\n");
		printf("Input the size of masive[1-10000]:");
	}
}

void inputChekerElement(int* n, int size)
{
	printf("Input element[%d]:", size);
	while (scanf_s("%d", &*n) != 1 || *n > MaxElement || *n < MinElement || getchar() != '\n')
	{
		rewind(stdin);
		printf("Error\n");
		printf("Input element[%d]:", size);
	}
}

int random(int min, int max)
{
	return min + rand() % (max - min + 1);
}

int* memory(int  n)
{
	int* mas;
	mas = (int*)calloc(n, sizeof(int));
	return mas;
}

void inputMasByHand(int* mas, int n)
{
	for (int i = 0; i < n; i++)
		inputChekerElement(&(*(mas + i)), (i + 1));
}

void inputMasRandom(int* mas, int n, int choise)
{
	srand(time(NULL));
	switch (choise)
	{
	case 0:
		for (int i = 0; i < n; i++)
			*(mas + i) = random(1, 100);
		break;

	case 1:
		for (int i = 0, j = n * 10; i < n; i++, j -= 10)
		{
			*(mas + i) = random(j - 10, j);
		}
		break;
	}
}

void showMas(int* mas, int n)
{
	int cheker = 0;
	for (int i = 0; i < n; i++)
	{
		printf("%6d", mas[i]);
	}
	printf("\n");
}

void masCopy(int* mas1, int* mas2, int n)
{
	for (int i = 0; i < n; i++)
		mas2[i] = mas1[i];

}

int chekerShel(int* mas, int i, int step, int n)
{
	for (int k = i; k < n - step; k += step)
		if (mas[k] > mas[k + step] && (mas[k] % 2 == 1 || mas[k] % 2 == -1) && (mas[k + step] % 2 == 1 || mas[k + step] % 2 == -1))
		{
			return 0;

		}
	return 1;
}

void sortShel(int* mas, int n)
{
	int storer;
	for (int step = n - 1; step > 0; step -= 1)
	{
		for (int j = 0; j < step; j++)
		{
			for (int k = j; k < n - step; k += step)
			{
				if (chekerShel(mas, k, step, n) == 1)
					break;
				if (mas[k] > mas[k + step] && (mas[k] % 2 == 1 || mas[k] % 2 == -1) && (mas[k + step] % 2 == 1 || mas[k + step] % 2 == -1))
				{
					storer = mas[k];
					mas[k] = mas[k + step];
					mas[k + step] = storer;
				}
			}
			if (chekerShel(mas, j, step, n) == 0)
			{
				j--;
			}
		}

	}
}

int chekerBubble(int* mas, int n)
{
	for (int i = 0; i < n; i++)
		if (mas[i] % 2 == 1)
			for (int j = i + 1; j < n; j++)
				if (mas[i] > mas[j] && (mas[j] % 2 == -1 || mas[j] % 2 == 1))
					return 0;
	return 1;
}

void sortBubble(int* mas, int n)
{
	while (chekerBubble(mas, n) == 0)
	{
		for (int i = 0; i < n; i++)
		{
			if (mas[i] % 2 == 1)
			{
				for (int j = i + 1; j < n; j++)
				{
					if (mas[i] > mas[j] && (mas[j] % 2 == -1 || mas[j] % 2 == 1))
					{
						int storer = mas[j];
						mas[j] = mas[i];
						mas[i] = storer;
						break;
					}
				}
			}
		}
	}
}

void timeComparator(float time1, float time2)
{
	if (time1 - time2 > 0)
		printf("\nBubble sort faster for %.3f seconds.\n", time1 - time2);
	if (time1 - time2 < 0)
		printf("\nShell sort faster for %.3f seconds.\n", time2 - time1);
	if (time1 == time2)
		printf("\nThey are equal.\n");
}