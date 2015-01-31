/*
 *  ex8_03.c
 *  xch09
 *
 *	calculate greatest common divisor of m and n 
 */

#include <stdio.h>

int gcd(int m, int n);

int main()
{
	int m, n;
	m = n = 0;
	
	printf("\n\nEnter two integers: ");
	scanf("%d %d", &m, &n);
	
	printf("Greatest common divisor: %d \n\n", gcd(m, n));
	
	return 0;
}

int gcd(int m, int n)
{
	int remainder = 0;
	
	while (n != 0)
	{
		remainder = m % n;
		m = n;
		n = remainder;	
	}	
	
	return m;
}