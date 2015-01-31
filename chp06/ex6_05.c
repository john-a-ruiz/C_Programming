/*
	get # from user then print it's reverse
	couldn't figure it out :(
*/

#include <stdio.h>

int main()
{
	int i, number, digit1, digit10;
	i = number = digit1 = digit10 = 0;
	
	printf("\n\nEnter a number: ");
	scanf("%d", &number);
	
	do
	{
		
	}
	
	digit10 = number / 10;
	digit1 = number % 10;
	
	printf("The reversal is: %d%d \n\n", digit1, digit10);

	return 0;
}