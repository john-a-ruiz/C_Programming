/*
 *  reverse.c
 *  xch08
 *
 *	prompt the user for a series of numbers then reverse the order
 */

#include <stdio.h>

#define N 10

int main()
{
	int a[N] = {0}, i = 0;
	
	printf("\n\nEnter %d numbers: ", N);
	for (i = 0; i < N; i++) 
		scanf("%d", &a[i]);
	
	printf("In reverse order: ");
	for (i = N - 1; i >= 0; i--)
		printf(" %d", a[i]);
	
	printf("\n\n");
	return 0;
}


