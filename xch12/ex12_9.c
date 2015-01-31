/*
 *  ex12_9.c
 *  xch12
 *
 *	simplify ex12_5b by using array name as pointer
 */

#include <stdio.h>
#include <ctype.h>

#define LETTERS 40

int main()
{
	char message[LETTERS] = {'0'};
	char *p_front, *p_back;
	p_front = p_back = message;
	
	printf("Enter a potential palindrome (<40 char): ");
	do *(p_back++) = getchar();
	while ((p_back < message+LETTERS) && (*(p_back-1) != '\n'));
	
	while (p_front < p_back)
		*p_front++ = toupper(*p_front);
	
	for (p_front = message, p_back -= 2; p_front <= p_back; p_front++, p_back--)
	{
		if ((*p_front < 65) || (*p_front > 90))
		{
			p_back++;
			continue;
		}
			
		if ((*p_back < 65) || (*p_back > 90))
		{
			p_front--;
			continue;
		}
			
		if (*p_front != *p_back)
		{
			printf("Not a Palindrome!\n\n");
			return 0;
		}
	}
	
	printf("We have a Palindrome!\n\n");
	return 0;
}
