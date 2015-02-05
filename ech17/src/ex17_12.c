/*
 * show output of program and explain what it does
 *
 * program prints 'Answer: 0' after it sends the pointer to f2 in the function f1. f1 sends f2 n += 1 for every iteration
 * while f2 returns negative numbers. When f2 returns 0 the program exits the while loop and returns '0' to main.
 */

#include <stdio.h>

int f1(int (*f)(int));
int f2(int i);

int main(void)
{
	printf("Answer: %d\n", f1(f2));

	return 0;
}

int f1(int (*f)(int))
{
	int n = 0;

	while((*f)(n))
		n++;

	return 0;
}

int f2(int i)
{
	return i * i + i - 12;
}
