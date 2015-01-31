/*
 *  ex11_7.c
 *  xch11
 *
 *	return pointer to middle element of array
 */

#include <stdio.h>

#define SIZE 5

int *find_middle(int numbers[], int size);

int main()
{
	int numbers[SIZE] = {1, 2, 3, 4, 5};
	int i = 0;
	int *middle = 0;
	
	printf("\n\nAn array is 5 long.");
	
	middle = find_middle(numbers, SIZE);
	
	printf("\nThe middle element is %d\n\n", *middle);
}

int *find_middle(int numbers[], int size)
{
	int middle = 0;
	
	middle = size / 2;
	
	return &numbers[middle];
}