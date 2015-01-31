/*
	determines the length of a message
*/

#include <stdio.h>

int main()
{
	int len = 0;
	
	printf("\n\nEnter a message: ");
	while (getchar() != '\n')
		len++;
		
	printf("Your message was %d characters long. \n\n", len);
	
	return 0;	
}