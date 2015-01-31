/*
	print a table of squares using a while loop
*/

#include <stdio.h>

int main()
{
	int i, n;
	i = n = 0;
	
	printf("\n\nThis program prints a table of squares. \n");
	printf("Enter number of entries in table: ");
	scanf("%d", &n);
	
	i = 1;
	while (i <= n)
	{
		printf("%10d%10d\n", i, i * i);
		i++;
	}
	
	printf("\n\n");
	return 0;
}