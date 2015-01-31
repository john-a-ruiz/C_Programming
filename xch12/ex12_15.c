/*
 *  ex12_15.c
 *  xch12
 *
 *	add loop (to 12_14) that prints highest temp for each day of week 
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
int find_largest(int temp[][Y], int *p_value, int day);

int main()
{
	int temp[X][Y] = {0};
	char week[7] = {'M', 'T', 'W', 'R', 'F', 'S', 'U'};
	int *p_value = &temp[0][0];
	char *p_day = &week[0];
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
	
	printf("\n\nHere are the highest temperatures for each day:\n");
	printf("\n\nDay\t\tHigh Temp\n");
	for (p_value = &temp[0][0], p_day = &week[0], day = 0; day < 7; day++, p_day++)
	{
		printf("%c\t\t%3d\n", *p_day, find_largest(temp, p_value, day));
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

int find_largest(int temp[][Y], int *p_value, int day)
{
	int max, hour;
	max = hour = 0;
	
	for (p_value = &temp[day][0]; hour < 24; p_value++, hour++)
		if (*p_value > max)
			max = *p_value;
	
	return max;
}






























