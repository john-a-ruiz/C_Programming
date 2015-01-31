/*
	sums a series of numbers using long int variables
*/

#include <stdio.h>

int main()
{
	double n, sum;
	n = sum = 0;
	
	printf("\n\nThis program sums a series of numbers. \n");
	printf("Enter numbers (0 to terminate): ");
	
	scanf("%lf", &n);
	while (n!= 0)
	{
		sum += n;
		scanf("%lf", &n);
	}
	printf("The sum is: %f\n\n", sum);
	
	return 0;
}