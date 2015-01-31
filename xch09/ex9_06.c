/*
 *  ex8_06.c
 *  xch09
 *
 *	returns kth digit from the right of number n
 */

#include <stdio.h>

int digit(int number, int shift);

int main()
{
	int number, shift;
	number = shift = 0;
	
	printf("\n\nEnter a number with several digits: ");
	scanf("%d", &number);
	
	printf("Enter a value less than the number of digits you just entered: ");
	scanf("%d", &shift);
	
	printf("\n%d digits from the right of %d is %d.\n\n", 
		   shift, number, digit(number, shift));
	
	return 0;
}

int digit(int number, int shift)
{
	int digit = 0;
	
	for (digit = 0; shift > 0; shift--)
	{
		if (number == 0)
			return -1;
		
		digit = number % 10;
		number /= 10;
	}
	
	return digit;
}
