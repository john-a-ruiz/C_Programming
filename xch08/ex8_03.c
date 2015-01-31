/*
 *  ex8_03.c
 *  xch08
 *
 *	enter several numbers to be tested for repeat digits
 */

#include <stdio.h>

int main()
{
	int digit_seen[10] = {0};
	int i, digit;
	long int n, number;
	i = digit = n = number = 0;
	
	do
	{
		printf("\n\nEnter a number (0 to terminate): ");
		scanf("%ld", &number);
		n = number;
		
		if (number <= 0)
			return 0;
		
		while (n > 0) 
		{
			digit = n % 10;
			digit_seen[digit] += 1;
			n /= 10;
		}
		
		printf("Digit:\t\t\t");
		for (i = 0; i < 10; i++)
			printf("%5d", i);
		
		printf("\nOccurrences:\t");
		for (i = 0; i < 10; i++)
			printf("%5d", digit_seen[i]);
		
		for (i = 0; i < 10; i++)
			digit_seen[i] = 0;
		
	} while (number > 0);

	
	printf("\n\n");
	return 0;
}


