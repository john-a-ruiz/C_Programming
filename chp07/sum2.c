/*
	sums a series of numbers using long int variables
*/

#include <stdio.h>

int main()
{
	long int n, sum;
	n = sum = 0;
	
	printf("\n\nThis program sums a series of integers. \n");
	printf("Enter integers (0 to terminate): ");
	
	scanf("%ld", &n);
	while (n!= 0)
	{
		sum += n;
		scanf("%ld", &n);
	}
	printf("The sum is: %ld\n\n", sum);
	
	return 0;
}