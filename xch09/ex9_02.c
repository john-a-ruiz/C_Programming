/*
 *  ex8_02.c
 *  xch09
 *
 *	returns 1 if both x and y fall between 0 and n-1
 */

#include <stdio.h>

typedef int Bool;

int check(int x, int y, int n);

int main()
{
	int x, y, n;
	x = y = n = 0;
	
	printf("\n\nO is at the bottom, what number is at the top? ");
	scanf("%d", &n);
	
	printf("\n\nGive me two numbers: ");
	scanf("%d%d", &x, &y);
	
	printf("Now if %d and %d fall between 0 and %d I'll output a 1.", x, y, n - 1);
	printf("\nAnswer: %d\n\n", check(x, y, n));
	
	return 0;
}

int check(int x, int y, int n)
{
	Bool x_flag, y_flag;
	x_flag = y_flag = 0;
	
	if (x >= 0 && x <= n-1)
		x_flag = 1;
	
	if (y >= 0 && y <= n-1)
		y_flag = 1;
	
	if (x_flag == 1 && y_flag == 1)
		return 1;
	else
		return 0;
}