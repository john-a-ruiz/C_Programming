/*
 *  ex12_4b.c
 *  xch12
 *
 *	read a message and print it's reverse using pointers
 */

#include <stdio.h>

#define LETTERS 20

int main()
{
	char message[LETTERS] = {'0'};
	char *p_letter = 0;
	
	printf("\n\nEnter a message (<20 characters): ");
	
	p_letter = &message[0];
	do *p_letter++ = getchar();
	while (p_letter < &message[LETTERS] && *(p_letter-1) != '\n');
	
	printf("The reverse is: ");
	while (p_letter-- >= &message[0])
	{
		if (*p_letter == '\n')
			continue;
		else
			putchar(*p_letter);
	}
	
	printf("\n\n");
	return 0;
}
