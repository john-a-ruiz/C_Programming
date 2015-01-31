/*
 *  ex8_04.c
 *  xch09
 *
 *	ask for mm/dd/yy and return in integer form 1-365
 */

#include <stdio.h>

int day_of_year(int month, int day, int year);

int main()
{
	int month, day, year;
	month = day = year = 0;
	
	printf("\n\nEnter a date (mm/dd/yy): ");
	scanf("%d/%d/%d", &month, &day, &year);
	
	printf("The day of year (1-366): %d\n\n", day_of_year(month, day, year));
	
	return 0;
}

int day_of_year(int month, int day, int year)
{
	int number = 0;
	
	for (month -= 1; month > 0; month--)
	{
		switch (month)
		{
			case 0:
				number = 0;
				break;
			case 1: case 3: case 5: case 7: case 8: case 10: case 12:
				number += 31;
				break;
			case 4: case 6: case 9: case 11:
				number += 30;
				break;
			case 2:
				if (year % 4 == 0)
					number += 29;
				else
					number += 28;
				break;
			default:
				printf("\n\nWTF!!\n\n");
				return 0;
		}
	}
	
	number += day;
	
	return number;
}
