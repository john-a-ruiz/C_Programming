/*
 *  ex9_17.c
 *  xch09
 *
 *	gets series of numbers then sorts them usint a recursive sort function
 */

#include <stdio.h>

#define SIZE (sizeof(array) / sizeof(array[0]))

void selection_sort(int array[], int size);
void shift(int array[], int size, int largest, int location);

int main()
{
	int array[5] = {0};
	int i = 0;
	
	printf("\n\nEnter 5 positive integers: ");
	for (i = 0; i < SIZE; i++)
		scanf("%d", &array[i]);
	
	selection_sort(array, SIZE);
	printf("Your 5 integers are now sorted: ");
	for (i = 0; i < SIZE; i++)
		printf("%d ", array[i]);
	
	printf("\n\n");
	return 0;
}

void selection_sort(int array[], int size)
{
	int i, largest, location;
	i = largest = location = 0;
	
	for (i = 0; i < size; i++)
		if (array[i] > largest)
		{
			largest = array[i];
			location = i;
		}
			
	//move largest element to last position in array
	shift(array, size, largest, location);
	
	if (size > 1)
		selection_sort(array, size-1);
}

void shift(int array[], int size, int largest, int location)
{
	int i = 0;
	
	if (largest == array[size-1])
		return;
	
	for (i = location; i < size-1; i++)
		array[i] = array[i+1];
	
	array[size-1] = largest;
}