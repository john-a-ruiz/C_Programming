/*
 *  ex11_5.c
 *  xch11
 *
 *	turns seconds since midnight into HH:MM:SS
 */

#include <stdio.h>

void split_time(long int total_sec, int *hr, int *min, int *sec);

int main()
{
	long int total_sec = 0;
	int hr, min, sec;
	hr = min = sec = 0;
	
	printf("\n\nEnter the number of seconds after midnight: ");
	scanf("%ld", &total_sec);
	
	split_time(total_sec, &hr, &min, &sec);
	
	printf("%ld seconds after midnight is \n", total_sec);
	printf("%.2d:%.2d:%.2d\n\n", hr, min, sec);
}

void split_time(long int total_sec, int *hr, int *min, int *sec)
{
	*hr = total_sec / 3600;
	*min = ((total_sec % 3600) / 60);
	*sec = ((total_sec % 3600) % 60);
}
