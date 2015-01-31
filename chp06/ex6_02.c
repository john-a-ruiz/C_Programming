/*
	enter 2 integers, the calculate and display their GCD
*/

#include <stdio.h>

int main()
{
	int m, n, remainder;
	m = n = remainder = 0;
	
	printf("\n\nEnter two integers: ");
	scanf("%d %d", &m, &n);
	
	while (n != 0)
	{
		remainder = m % n;
		m = n;
		n = remainder;	
	}	
	
	printf("Greatest common divisor: %d \n\n", m);
	
	return 0;
}