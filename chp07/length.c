/*
	determines the length of a message
*/

#include <stdio.h>

int main()
{
	char ch;
	int length;
	ch = length = 0;
	
	printf("\n\nEnter a message: ");
	ch = getchar();
	while (ch != '\n')
	{
		length++;
		ch = getchar();
	}	
	
	printf("Your message was %d characters long. \n\n", length);
	
	return 0;
}