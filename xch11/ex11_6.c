/*
 *  ex11_6.c
 *  xch11
 *
 *	find largest and second largest from a wad of numbers
 */

#include <stdio.h>

#define SIZE 5

void find_two_largest(int numbers[], int size, int *largest, int *second_largest);

int main()
{
	int numbers[SIZE] = {0};
	int i, largest, second_largest;
	i = largest = second_largest = 0;
	
	printf("\n\nEnter 5 random integers: ");
	for (i = 0; i < SIZE; i++)
		scanf("%d", &numbers[i]);
	
	find_two_largest(numbers, SIZE, &largest, &second_largest);
	
	printf("The largest number: %d\n", largest);
	printf("The second largest number: %d\n\n", second_largest);
}

void find_two_largest(int numbers[], int size, int *largest, int *second_largest)
{
	int i = 0;
	
	*largest = *second_largest = numbers[0];
	
	for (i = 1; i < size; i++)
		if (numbers[i] > *largest)
			*largest = numbers[i];
	
	for (i = 1; i < size; i++)
		if (numbers[i] > *second_largest && numbers[i] < *largest)
			*second_largest = numbers[i];
}
