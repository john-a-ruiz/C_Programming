/*
 *  ex8_10.c
 *  xch09
 *
 *	return largest element in array, average of elements in array, 
 *	number of positive elements in array
 */

#include <stdio.h>

int largest(int array[], int size);
float average(int array[], int size);
int positive(int array[], int size);

int main()
{
	int array[5] = {0};
	int i;
	i = 0;
	
	printf("\n\nEnter 5 integers: ");
	for (i = 0; i < 5; i++)
		scanf("%d", &array[i]);
	
	printf("\nThe largest element is %d", largest(array, 5));
	printf("\nThe average of the elements is %.2f", average(array, 5));
	printf("\nThe number of positive elements is %d \n\n", positive(array, 5));
	
	return 0;
}

int largest(int array[], int size)
{
	int i, largest;
	i = largest = 0;
	
	for (i = 0; i < size; i++)
		if (array[i] > largest)
			largest = array[i];
	
	return largest;
}

float average(int array[], int size)
{
	int i;
	float sum, average;
	i = average = sum = 0;
	
	for (i = 0; i < size; i++)
		sum += array[i];
	
	average = sum / size;
	
	return average;
}

int positive(int array[], int size)
{
	int i, positive;
	i = positive = 0;
	
	for (i = 0; i < size; i++)
		if (array[i] > 0)
			positive++;
	
	return positive;
}