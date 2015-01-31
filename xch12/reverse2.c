/*
 *  reverse2.c
 *  xch12
 *
 *  reverses a series of numbers (pointer version)
 */

#include <stdio.h>

#define N 10

int main()
{
	int a[N], *p;
	
	printf("\n\nEnter %d numbers: ", N);
	for (p = a; p < a+N; p++)
		scanf("%d", p);
	
	printf("\nIn reverse order:");
	for (p = a+N-1; p >= a; p--)
		printf(" %d", *p);
	
	printf("\n\n");
	return 0;
}

