/*
 *  ex12_4.c
 *  xch12
 *
 *	read a message and print it's reverse
 */

#include <stdio.h>

#define LETTERS 20

int main()
{
	char message[LETTERS] = {0};
	int i = 0;
	
	printf("\n\nEnter a message (<20 letters): ");
	
	i = 0;
	do message[i++] = getchar();
	while (message[i-1] != '\n' && i < LETTERS);
	
	printf("The reversal is: ");
	for (i = LETTERS-1; i >= 0; i--)
	{
		if (message[i] == '\n')
			continue;
		else
			putchar(message[i]);
	}

	printf("\n\n");
	return 0;
}


