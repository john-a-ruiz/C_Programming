/*
	ask user to enter taxable income the display the tax due
*/

#include <stdio.h>

int main()
{
	float income = 0;
	
	printf("\n\nHow much $$$ you make: $");
	scanf("%f", &income);
	
	printf("How much $$$ you owe: $");
	
	if (income < 750.00)
		printf("%.2f", income * .01);
	else if (750.00 <= income && income < 2250.00)
		printf("%.2f", 7.50 + ((income - 750.00) * .02));
	else if (2250.00 <= income && income < 3750.00)
		printf("%.2f", 37.50 + ((income - 2250.00) * .03));
	else if (3750.00 <= income && income < 5250.00)
		printf("%.2f", 82.50 + ((income - 3750.00) * .04));
	else if (5250.00 <= income && income < 7000.00)
		printf("%.2f", 142.50 + ((income - 5250.00) * .05));
	else
		printf("%.2f", 230.00 + ((income - 7000.00) * .06));	
	printf("\n\n");
	
	return 0;	
}	