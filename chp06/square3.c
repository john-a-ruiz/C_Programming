/*
	prints a table of squares using an odd method
*/

#include <stdio.h>

int main()
{
	int i, n, odd, square;
	i = n = odd = square = 0;
	
	printf("\n\nThis program prints a table of squares,\n");
	printf("Enter number of entries in table: ");
	scanf("%d", &n);
	
	i = 1;
	odd = 3;
	for (square = 1; i <= n; odd += 2)
	{
		printf("%10d%10d\n", i, square);
		++i;
		square += odd;
	}
	
	printf("\n\n");
	return 0;
}