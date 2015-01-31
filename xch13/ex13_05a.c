/*
 *  13_5a.c
 *  xch13
 *
 *	write a function that caps all letters using array subscripting
 */

#include <stdio.h>
#include <ctype.h>

#define CHARACTERS 100

int read_line(char array[], int size);
void strcap(char array[], int size);

int main()
{
	char line[CHARACTERS+1] = {'0'};
	int length = 0;
	
	printf("\n\nEnter some input so I can capitilize it: ");
	length = read_line(line, CHARACTERS);
	
	strcap(line, length);
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

void strcap(char array[], int size)
{
	int i = 0;
	
	while (i < size)
		array[i++] = toupper(array[i]);
}
