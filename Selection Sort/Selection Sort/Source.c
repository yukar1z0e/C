#include <stdio.h>
#include <math.h>

#define MAX_SIZE 101
#define SWAP(x, y, t)  ((t) = (x), (x) = (y), (y) = (t))

 //selection sort
void sort(int[], int);     

void sort(int list[], int n)
{
	int i, j, min, temp;
	for (i = 0; i < n - 1; i++) {
		min = i;
		for (j = i + 1; j < n; j++)
			if (list[j] < list[min])
				min = j;
		SWAP(list[i], list[min], temp);
	}
}

void main(void)
{
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
	sort(list, n);

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


