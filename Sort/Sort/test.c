#include"sort.h"
#include <stdio.h>
#include <math.h>

void main(void)
{
	//test selection sort

	int i, n;
	int list[MAX_SIZE];

	printf("Enter the number of numbers to generate: ");

	scanf_s("%d", &n);

	if (n < 1 || n > MAX_SIZE)
	{
		fprintf(stderr, "Improper value of n\n");
		exit(1);
	}

	//randomly generate numbers
	for (i = 0; i < n; i++)
	{
		list[i] = rand() * 1000;
		printf("%d ", list[i]);
	}
	selection_sort(list, n);

	printf("\n Sorted array:\n");

	//print out sorted numbers
	for (i = 0; i < n; i++)
	{
		printf("%d ", list[i]);
	}
	printf("\n");


	system("pause");

	return;
}
