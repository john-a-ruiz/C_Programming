/*
	get two digit # from user then print it's reverse
*/

#include <stdio.h>

int main()
{
	int number, digit1, digit10;
	number = digit1 = digit10 = 0;
	
	printf("\n\nEnter a two-digit number: ");
	scanf("%d", &number);
	
	digit10 = number / 10;
	digit1 = number % 10;
	
	printf("The reversal is: %d%d \n\n", digit1, digit10);

	return 0;
}