/*
 *  ex13_16.c
 *  xch13
 *
 *	condense the count_spaces fcn, replace 'for' with 'while'
 */

#include <stdio.h>
#include <string.h>

#define LETTERS 50

int read_line(char array[], int size);
int count_spaces(const char *s);

int main()
{
	char line[LETTERS+1] = {'\0'};
	
	printf("\n\nEnter a sentence: ");
	read_line(line, LETTERS);
	
	printf("In that line you have %d spaces.\n\n", count_spaces(line));
	
	return 0;
}

int read_line(char array[], int size)
{
	char ch = '0';
	int i = 0;
	
	while ((ch = getchar()) == ' ')
		;
	array[i++] = ch;
	
	while (((ch = getchar()) != '\n') && (i < size))
		array[i++] = ch;
	
	array[i] = '\0';
	
	return i;
}

/* Initial
int count_spaces(const char *s)
{
	int count = 0;
	
	for ( ; *s != '\0'; s++)
		if (*s == ' ')
			count++;
	
	return count;
}
*/

// Re-written
int count_spaces(const char *s)
{
	int count = 0;
	
	while (*s++)
		if (*s == ' ')
			count++;
	
	return count;
}

