/*
 *  ex8_01.c
 *  xch08
 *
 *	shows which digits (if any) were repeated
 */

#include <stdio.h>

#define TRUE 1
#define FALSE 0

typedef int Bool;

int main()
{
	Bool digit_seen[10] = {0}, repeat;
	int repeated_digits[10] = {0};
	int i, digit;
	long int n;
	i = digit = n = repeat = 0; 
	
	printf("\n\nEnter a number: ");
	scanf("%ld", &n);
	
	while (n > 0) 
	{
		digit = n % 10;
		if (digit_seen[digit])
		{
			repeated_digits[digit] += 1;
			repeat = TRUE;
		}
		
		digit_seen[digit] = TRUE;
		n /= 10;
	}
	
	if (repeat == TRUE)
	{
		printf("Repeated digits:");
		for (i = 0; i <= 9; i++)
		{
			if (repeated_digits[i] != 0)
				printf(" %d", i);
		}
		printf("\n\n");
	}
	else
		printf("No repeated digits \n\n");
	
	return 0;
}



