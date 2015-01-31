/*
 *  ex8_02.c
 *  xch08
 *
 *	print a table showing how many times a digit was repeated
 */

#include <stdio.h>

int main()
{
	int digit_seen[10] = {0};
	int i, digit;
	long int n;
	
	i = digit = n = 0;
	
	printf("\n\nEnter a number: ");
	scanf("%ld", &n);
	
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

	printf("\n\n");
	return 0;
}
