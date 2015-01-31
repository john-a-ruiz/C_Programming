/*
	print a user specified one-month calendar
*/

#include <stdio.h>

int main()
{
	int i, j, length, start;
	i = j = length = start = 0;
	
	printf("\n\nEnter number of days in month: ");
	scanf("%d", &length);
	
	printf("Enter starting day of the week (1=Sun, 7=Sat): ");
	scanf("%d", &start);
	
	for (i = 1; i < start; i++)
		printf("     ");
		
	for (j = 1; j <= length; i++, j++)
	{
		printf("%5d", j);
		
		if (i % 7 == 0)
			printf("\n");
	}
	
	printf("\n\n");
	return 0;
}