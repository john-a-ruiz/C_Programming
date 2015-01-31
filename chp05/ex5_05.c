/*
	determines the number of digits in a number
*/

#include <stdio.h>

int main()
{
	int number, digits;
	number = digits = 0;
	
	printf("\n\nEnter a positive number (max 4 digits): ");
	scanf("%d", &number);
	
	if (number <= 9)
		digits = 1;
	else if (10 <= number && number <= 99)
		digits = 2;
	else if (100 <= number && number <= 999)
		digits = 3;
	else if (1000 <= number && number <= 9999)
		digits = 4;
		
	switch (digits)
	{
		case 1: 
			printf("The number %d has %d digit \n\n", number, digits); break;
		case 2: case 3: case 4:
			printf("The number %d has %d digits \n\n", number, digits); break;
	}
	
	return 0;
}