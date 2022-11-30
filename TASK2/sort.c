#include"sort.h"
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

#define MaxElement 1000
#define MinElement -1000
#define MaxSize 100
#define MinSize 1

int random(int min, int max)
{
	return min + rand() % (max - min + 1);
}

void choiseFunction(int* choise)
{
	while (scanf_s("%d", choise) != 1 || *choise < 0 || *choise>1 || getchar() != '\n')
	{
		rewind(stdin);
		printf("Error\n");
		printf("If you want random input 1. If you want input masive by hands input 0.\n");
	}

}

void inputChekerElement(int* n, int row, int col)
{
	printf("Input element[%d][%d]:", row, col);
	while (scanf_s("%d", &*n) != 1 || *n > MaxElement || *n < MinElement || getchar() != '\n')
	{
		rewind(stdin);
		printf("Error\n");
		printf("Input element[%d][%d]:", row, col);
	}

}

void inputChekerRow(int* n)
{
	while (scanf_s("%d", &*n) != 1 || *n > MaxSize || *n < MinSize || getchar() != '\n')
	{
		rewind(stdin);
		printf("Error\n");
		printf("Input how much rows in masive[1-100]:");
	}
}

void inputChekerColumn(int* n)
{
	while (scanf_s("%d", n) != 1 || *n > MaxSize || *n < MinSize || getchar() != '\n')
	{
		rewind(stdin);
		printf("Error\n");
		printf("Input how much columns in masive[1-100]:");
	}
}

int** memory(int n, int m)
{
	int** mas;
	mas = (int**)calloc(n, sizeof(int*));
	for (int i = 0; i < n; i++)
	{
		*(mas + i) = (int*)calloc(m, sizeof(int));
	}
	return mas;
}

void inputMasByHand(int** mas, int n, int m)
{
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
		{

			inputChekerElement(&(*(*(mas + i) + j)), (i + 1), (j + 1));
		}
}

void inputMasRandom(int** mas, int n, int m)
{
	srand(time(NULL));
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
		{
			(*(*(mas + i) + j)) = random(0, 5);
		}
}

void showMas(int** mas, int n, int m)
{
	int cheker = 0;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
			printf("%4d", *(*(mas + i) + j));
		printf("\n");
		printf("       ");
	}
	printf("\n");
}

int sumCheker(int** mas, int n,int col_num)
{
	int sum=0;
	for (int i = 0; i < n; i++)
		if (*(*(mas + i) + col_num) % 2 == 0)
			sum += *(*(mas + i) + col_num);

	return sum;

}

void changerCol(int **mas,int n,int n_col1,int n_col2)
{
	int storer;
	for (int i = 0; i < n; i++)
	{
		storer = *(*(mas + i) + n_col2);
		for(int j=n_col2;j>n_col1;j--)
			*(*(mas + i) + j)= *(*(mas + i) + j-1);
		*(*(mas + i) + n_col1) = storer;
	}

}

int findMin(int** mas,int n, int first, int last)
{
	int min=sumCheker(mas,n,first),n_col=first;
	for (int i = first+1; i < last+1; i++)
		if (sumCheker(mas, n, i) < min)
		{
			min = sumCheker(mas, n, i);
			n_col = i;
		}

	return n_col;
}

void sortSl(int** mas, int n, int first,int last)
{		
	int col_change;	
	if (first < last)
	{
		sortSl(mas, n,  first, (first + last) / 2);
		sortSl(mas, n, ( (first + last) / 2 )+ 1, last);
		for (int i = first; i < last; i++)
		{
			col_change = findMin(mas, n, i, last);
			changerCol(mas, n, i, col_change);		
		}
	}
}








