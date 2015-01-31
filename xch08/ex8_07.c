/*
 *  ex8_07.c
 *  xch08
 *
 *	turn normal text into Biff Speak
 */

#include <stdio.h>
#include <ctype.h>

#define ARRAY_SIZE (sizeof(normal) / sizeof(normal[0]))

int main()
{
	char normal[100] = {0};
	int i, j;
	i = j = 0;
	
	printf("\n\nEnter message: ");
	i = 0;
	do normal[i++] = getchar();
	while (i < ARRAY_SIZE && normal[i-1] != '\n');
	
	printf("In B1FF-speak: ");
	for (i = 0; i < ARRAY_SIZE && normal[i] != '\n'; i++)
	{
		normal[i] = toupper(normal[i]);
		
		if (normal[i] == 'A')
			normal[i] = '4';
		
		if (normal[i] == 'B')
			normal[i] = '8';
		
		if (normal[i] == 'E')
			normal[i] = '3';
		
		if (normal[i] == 'I')
			normal[i] = '1';
		
		if (normal[i] == 'O')
			normal[i] = '0';
		
		if (normal[i] == 'S')
			normal[i] = '5';
		
		putchar(normal[i]);
	}
	
	printf("!!!!!!!!!!\n\n");
	return 0;
}


