/*
	user enters number then prints all even squares between 1 and n
*/

#include <stdio.h>

int main()
{
	int i, number, square;
	i = number = square = 0;
	
	printf("\n\nEnter an integer number: ");
	scanf("%d", &number);
	
	for (i = 2; square < number; i += 2)
	{
		square = i * i;
		printf("%d\n", square);
	} 
	
	printf("\n\n");
	return 0;
}