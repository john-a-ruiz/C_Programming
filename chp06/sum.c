/*
	sums a series of numbers
*/

#include <stdio.h>

int main()
{
	int n, sum;
	n = sum = 0;
	
	printf("\nThis program sums a series of integers.\n");
	printf("Enter integers (0 to terminate): ");
	
	scanf("%d", &n);
	while (n != 0)
	{
		sum += n;
		scanf("%d", &n);
	}
	printf("The sum is: %d\n\n", sum);
	
	return 0;
}