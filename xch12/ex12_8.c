/*
 *  ex12_8.c
 *  xch12
 *
 *	simplify ex12_4b by using array name as pointer
 */

#include <stdio.h>

#define LETTERS 40

int main()
{
	char message[LETTERS] = {'0'};
	char *p_letter = message;
	
	printf("\n\nEnter a message (<40 char): ");
	do *(p_letter++) = getchar();
	while ((p_letter != message+LETTERS) && (*(p_letter-1) != '\n'));
	
	printf("Reversal is: ");
	p_letter -= 2;
	while (p_letter >= message)
		putchar(*p_letter--);
	
	printf("\n\n");
	return 0;
}
