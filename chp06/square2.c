/*
	prints a table of squares using a for loop
*/

#include <stdio.h>

int main()
{
	int i, n;
	i = n = 0;
	
	printf("\n\nThis program prints a table of squares.\n");
	printf("Enter number of entries in table: ");
	scanf("%d", &n);
	
	for (i = 0; i <= n; i++)
		printf("%10d%10d\n\n", i, i * i);
	
	return 0;
}