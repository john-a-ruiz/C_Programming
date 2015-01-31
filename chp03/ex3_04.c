/*
	accept date in mm/dd/yy format then display in yymmdd
*/

#include <stdio.h>

int main()
{
	int month = 0, day = 0, year = 0;
	
	printf("\n\n\nEnter a date (mm/dd/yy): ");
	scanf("%d/ %d/ %d", &month, &day, &year);
	
	printf("You entered the date %.2d%.2d%.2d \n\n\n", year, month, day);
	
	return 0;
}