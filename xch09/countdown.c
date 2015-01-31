/*
 *  countdown.c
 *  xch09
 *
 *	prints a countdown
 */

#include <stdio.h>

void print_count(int n)
{
	printf("T minus %d and counting\n", n);
}

int main()
{
	int i = 0;
	
	printf("\n\n");
	for (i = 10; i > 0; --i)
		print_count(i);
	printf("\n\n");
	
	return 0;
}

