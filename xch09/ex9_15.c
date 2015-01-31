/*
 *  ex9_15.c
 *  xch09
 *
 *	a recursive function that computes the gcd of two numbers
 */

#include <stdio.h>

int gcd(int m, int n);
int gcd_r(int m, int n);

int main()
{
	int m, n;
	m = n = 0;
	
	printf("\n\nEnter two integers: ");
	scanf("%d %d", &m, &n);
	
	printf("Greatest common divisor: %d \n\n", gcd_r(m, n));
	
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

int gcd_r(int m, int n)
{
	if (n == 0)
		return m;
	else
		gcd_r(n, m % n);
}