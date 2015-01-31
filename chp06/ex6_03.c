/*
	ask user to enter a fraction then convert to lowest terms
*/

#include <stdio.h>

int main()
{
	int m, n, numerator, denominator, remainder;
	m = n = numerator = denominator = remainder = 0;
	
	printf("\n\nEnter a fraction: ");
	scanf("%d/%d", &m, &n);
	numerator = m;
	denominator = n;
	
	//compute GCD
	while (n != 0)
	{
		remainder = m % n;
		m = n;
		n = remainder;
	}
	
	printf("In lowest terms: %d/%d \n\n", numerator / m, denominator / m);
	
	return 0;
}