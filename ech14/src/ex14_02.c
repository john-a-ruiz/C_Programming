/*
 ============================================================================
 Name        : ex14_02.c
 Author      :
 Version     :	just can't replace sizeof with macro of sizeof???????
 Copyright   :
 Description : write macro the computes the num of elements in 1D array
 ============================================================================
 */

#include <stdio.h>
#include <string.h>

#define SIZE 40
#define NELEMS(a) (sizeof(a));

void read_line(char array[], int size);

int main(void)
{
	char elements[SIZE+1] = {0};

	printf("Give me a line of characters, you character: ");
	read_line(elements, SIZE);

	printf("The number of bytes in the array is %d", sizeof(elements));

	return 0;
}

void read_line(char array[], int size)
{
	int i = 0;
	char ch = 0;

	while ((ch = getchar()) == ' ')
		;
	array[i++] = ch;

	while (((ch = getchar()) != '\n') && (i < size))
		array[i++] = ch;

	array[i] = '\0';
}
