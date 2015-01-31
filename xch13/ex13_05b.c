/*
 *  ex13_5b.c
 *  xch13
 *
 *	write a function that caps all letters using pointers
 */

#include <stdio.h>
#include <ctype.h>

#define CHARACTERS 100

int read_line(char array[], int size);
void strcap(char *p_element);

int main()
{
	char line[CHARACTERS+1] = {'0'};
	char *p_character = &line[0];
	int length = 0;
	
	printf("\n\nEnter some input so I can capitilize it: ");
	length = read_line(line, CHARACTERS);
	
	strcap(p_character);
	printf("Capitilized it looks like:\n%s\n\n", line);
	
	return 0;
}

int read_line(char array[], int size)
{
	char ch;
	int i = 0;
	
	while ((ch = getchar()) == ' ');
	array[i++] = ch;
	
	while ((ch = getchar()) != '\n')
		if (i < size)
			array[i++] = ch;
		else
			break;
	
	array[i] = '\0';		//terminate string
	return i;			//return length of string
}

void strcap(char *p_element)
{	
	while (*p_element != '\0')
		*p_element++ = toupper(*p_element);
}


