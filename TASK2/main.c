#include"sort.h"
#include<stdio.h>

int main()
{
	int** mas, n_row = 0, n_col = 0, choise = -1;
	printf("If you want random input 1. If you want input masive by hands input 0.\n");
	choiseFunction(&choise);
	printf("Input how much rows in masive[1-100]:");
	inputChekerRow(&n_row);
	printf("Input how much columns in masive[1-100]:");
	inputChekerColumn(&n_col);
	mas = memory(n_row, n_col);
	if (choise == 0)
	{
		printf("All elements should be in range[-1000;1000].\n");
		inputMasByHand(mas, n_row, n_col);
	}
	if (choise == 1)
	{
		inputMasRandom(mas, n_row, n_col);
	}
	printf("Masive:");
	showMas(mas, n_row, n_col);
	printf("\n");
	sortSl(mas, n_row,0,n_col-1);
	printf("Result:");
	showMas(mas, n_row, n_col);
	return 0;
}