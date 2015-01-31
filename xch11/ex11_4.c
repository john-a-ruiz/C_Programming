/*
 *  ex11_4.c
 *  xch11
 *
 *	write the swap function
 */

#include <stdio.h>

void swap(int *x, int *y);

int main()
{
	int x, y;
	x = y = 0;
	
	printf("\n\nEnter an x value: ");
	scanf("%d", &x);
	
	printf("Enter a y value: ");
	scanf("%d", &y);
	
	swap(&x, &y);
	
	printf("\n\nSwapped x: %d", x);
	printf("\nSwapped y: %d\n\n", y);
}

void swap(int *x, int *y)
{
	int temp = 0;
	
	temp = *x;
	*x = *y;
	*y = temp;
}


