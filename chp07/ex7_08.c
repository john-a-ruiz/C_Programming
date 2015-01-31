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
	getchar(); /*to eat up the unused \n from scanf*/
	
	for (i = 1; i <= n; i++)
	{
		printf("%10d%10d\n", i, i * i);
		
		if (i % 24 == 0)
		{
			printf("\nPress Enter to continue... ");
			while (getchar() != '\n')
				;
			printf("\n");
		}
	}
	printf("\n\n");
	return 0;
}