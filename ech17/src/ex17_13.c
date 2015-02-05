/*
 * the call sum(g, i, j) should return g(i) + .... + g(j).
 *
 * int sum(int (*f)(int), int start, int end);
 */

#include <stdio.h>

int sum(int (*f)(int), int start, int end);
int g(int n);

int main(void)
{
	int i, j;
	i = j = 0;

	printf("Give me a number to start with: ");
	scanf("%d", &i);

	printf("Give me a number to end with: ");
	scanf("%d", &j);

	sum(g, i, j);

	return 0;
}

int sum(int (*f)(int), int start, int end)
{
	while (start < end)
	{
		g(start);
		start += 1;
	}

	printf("g(%d)\n\n", end);

	return 0;
}

int g(int n)
{
	printf("g(%d) + ", n);

	return 0;
}
