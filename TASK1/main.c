#include<stdio.h>
#include<time.h>
#include"sort.h"

int main()
{
	int* mas1, * mas2, size, choise1, choise2;
	printf("If you want random input 1. If you want input masive by hands input 0.\n");
	choiseFunction(&choise1,1);
	printf("Input the size of masive[1-10000]:");
	inputChekerSize(&size);
	mas1=memory(size);
	mas2 = memory(size);
	if (choise1 == 0)
		inputMasByHand(mas1, size);
	if (choise1 == 1)
	{
		printf("Do you want worse variant?(Yes-1,No-0):");
		choiseFunction(&choise2,2);
		inputMasRandom(mas1, size,choise2);
	}
	masCopy(mas1, mas2, size);
	printf("Masive:");
	showMas(mas1, size);
	clock_t start1 = clock();
	sortShel(mas1, size);
	clock_t end1 = clock();
	float time1 = (float)(end1 - start1) / CLOCKS_PER_SEC;
	clock_t start2 = clock();
	sortBubble(mas2, size);
	clock_t end2 = clock();
	float time2 = (float)(end2 - start2) / CLOCKS_PER_SEC;
	printf("\nResult of Shells sort:");
	showMas(mas1, size);
	printf("It takes about %.3f seconds\n",time1);
	printf("\nResult of Bubble sort:");
	showMas(mas2, size);
	printf("It takes about %.3f seconds\n", time2);
	timeComparator(time1, time2);
	return 0;
}