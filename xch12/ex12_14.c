/*
 *  ex12_14.c
 *  xch12
 *
 *	print temps stored in row i of array using pointer
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define X 7
#define Y 24
#define MAX_TEMP 110

void initialize_temp_generator(void);
void populate_temp_array(int temp[][Y], int *p_value); 
int choose_temp(void);

int main()
{
	int temp[X][Y] = {0};
	int *p_value = &temp[0][0];
	int day, hour;
	
	day = hour = 0;
	
	initialize_temp_generator();
	populate_temp_array(temp, p_value);
	
	printf("\n\nPick a day to see it's temps (1-7): ");
	scanf("%d", &day);
	
	printf("\n\nhour\t\t\ttemp\n");
	for (p_value = &temp[day-1][0]; hour < 24; p_value++)
	{
		printf("%4d\t\t\t%4d\n", ++hour, *p_value);
	}
	
	return 0;
}

void initialize_temp_generator(void)
{
	srand((unsigned) time(NULL));
}

void populate_temp_array(int temp[][Y], int *p_value)
{
	for (p_value = &temp[0][0]; p_value <= &temp[X-1][Y-1]; p_value++)
		*p_value = choose_temp();
}

int choose_temp(void)
{
	return rand() % MAX_TEMP;
}