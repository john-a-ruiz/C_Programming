/*
 *  ex12_5b.c
 *  xch12
 *
 *  read message and see if it's a palandrome using pointers
 */

#include <stdio.h>
#include <ctype.h>

#define LETTERS 40

int main()
{
	char message[LETTERS] = {'0'};
	char *p_head, *p_tail;
	p_head = p_tail = 0;
	
	printf("\n\nEnter a message (<40 char): ");
	
	// get message from user
	p_tail = message;
	do *p_tail++ = getchar();
	while ((p_tail < message+LETTERS) && (*(p_tail-1) != '\n'));
	
	// convert chars to upper case
	for (p_head = message; *p_head != '\n'; p_head++)
		*p_head = toupper(*p_head);
	
	// check to see if palindrome
	for (p_head = message, p_tail -= 2; p_head < p_tail; p_head++, p_tail--)
	{
		if ((*p_head < 65) || (*p_head > 90))
		{
			p_tail++;
			continue;
		}
		
		if ((*p_tail < 65) || (*p_tail > 90))
		{
			p_head--;
			continue;
		}
		
		if (*p_head != *p_tail)
		{
			printf("Not a Palindrome!\n\n");
			return 0;
		}
	}
	
	printf("Palindrome!\n\n");
	return 0;
}
