/*
 *  ex9_14.c
 *  xch09
 *
 *	a non recursive factorial function
 */

#include <stdio.h>

int factorial(int number); 

int main()
{
	int number = 0;
	
	printf("\n\nEnter an integer value: ");
	scanf("%d", &number);
	
	printf("The factorial of %d is %d. \n\n", number, factorial(number));
}

int factorial(int number)
{
	int factorial = 0;
	
	for (factorial = number; number > 1; number--)
		factorial *= (number - 1);
	
	return factorial;
}
