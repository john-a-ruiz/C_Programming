/*
	ask user for 24 hour time then display in 12 hour time
*/

#include <stdio.h>

int main()
{
	int hour, minute;
	hour = minute = 0;
	
	printf("\n\nEnter a 24-hour time (hh:mm): ");
	scanf("%d:%d", &hour, &minute);
	
	if (hour < 12 || hour == 24)
		printf("Equivalent 12-hour time: %d:%.2d am \n\n", hour == 24 ? 12 : hour, minute);
	else
		printf("Equivalent 12-hour time: %d:%.2d pm \n\n", hour == 12 ? 12 : hour - 12, minute);
	
	return 0;
}