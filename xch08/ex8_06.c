/*
 *  ex8_06.c
 *  xch08
 *
 *	compounds interest monthly and is shown in annual intervals
 */

#include <stdio.h>

#define NUM_RATES (sizeof(value) / sizeof(value[0]))
#define INITIAL_BALANCE 100.00

int main()
{
	int i, j, low_rate, num_years, year;
	float value[5] = {0};
	i = j = low_rate = num_years = year = 0;
	
	printf("\n\nEnter interest rate: ");
	scanf("%d", &low_rate);
	
	printf("Enter number of years: ");
	scanf("%d", &num_years);
	
	printf("\nYears");
	for (i = 0; i < NUM_RATES; i++) 
	{
		printf("%8d%%", low_rate + i);
		value[i] = INITIAL_BALANCE;
	}
	printf("\n");
	
	for (year = 1; year <= num_years; year++) 
	{
		printf("%3d   ", year);
		for (i = 0; i < NUM_RATES; i++) 
		{
			//compound interest monthly
			for (j = 0; j < 12; j++)
			{
				value[i] += (low_rate + i) / 100.00 * value[i];
			}
			printf("%9.2f", value[i]);
		}
		printf("\n");
	}
	printf("\n\n");
	
	return 0;
}
