/*
 *  ex8_05.c
 *  xch09
 *
 *	return number of digits in a number
 */

#include <stdio.h>

int num_digits(int number);

int main()
{
	int number = 0;
	
	printf("\n\nGimme a number: ");
	scanf("%d", &number);
	
	printf("Your number has %d digits.\n\n", num_digits(number));
}

int num_digits(int number)
{
	int digits = 0;
	
	for (digits = 0; number > 0; digits++)
	{
		number /= 10;
	}
	
	return digits;
}
