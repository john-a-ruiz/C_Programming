/*
 *  ex8_05.c
 *  xch08
 *
 *	use fancy way to find array length
 */

#include <stdio.h>

#define N 10
#define SIZE (sizeof(a) / sizeof(a[0]))

int main()
{
	int a[N] = {0}, i = 0;
	
	printf("\n\nEnter %d numbers: ", N);
	for (i = 0; i < SIZE; i++) 
		scanf("%d", &a[i]);
	
	printf("In reverse order: ");
	for (i = SIZE - 1; i >= 0; i--)
		printf(" %d", a[i]);
	
	printf("\n\n");
	return 0;
}


