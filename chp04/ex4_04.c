/*
	get two digit # from user then print it's reverse
*/

#include <stdio.h>

int main()
{
	int number, digit1, digit10, digit100;
	number = digit1 = digit10 = digit100 = 0;
	
	printf("\n\nEnter a three-digit number: ");
	scanf("%d", &number);
	
	digit100 = number / 100; number %= 100;
	digit10 = number / 10;
	digit1 = number % 10;
	
	printf("The reversal is: %d%d%d \n\n", digit1, digit10, digit100);

	return 0;
}