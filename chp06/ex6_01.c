/*
	find the largest in a series of numbers entered by the user. 
	when user enters 0 or negative number the program displays largest number
*/

#include <stdio.h>

int main()
{
	float number, largest;
	number = largest = 0.0;
	
	printf("\n\nEnter a number: ");
	scanf("%f", &number);
	
	while (number > 0.0)
	{
		if (number > largest)
			largest = number;
			
		printf("Enter a number: ");
		scanf("%f", &number);
	}
	
	printf("\nThe largest number you entered was: %.2f \n\n", largest);
	
	return 0;
}