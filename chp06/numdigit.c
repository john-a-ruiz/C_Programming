/*
	calculates the number of digits in an integer
*/

#include <stdio.h>

int main()
{
	int digits, n;
	digits = n = 0;
	
	printf("\n\nEnter a nonnegative integer: ");
	scanf("%d", &n);
	
	do
	{
		n /= 10;
		digits++;
	} while (n > 0);
	
	printf("The number has %d digit(s). \n\n", digits);
	
	return 0;
}