/*
 * write function 'duplicate' that uses malloc to create a copy of a string and returns a pointer to the copy
 */

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define LENGTH 20

void read_line(char array[], int size);
char *duplicate(char array[]);

int main(void)
{
	char message[LENGTH+1] = {0};
	char *copy = 0;

	printf("Give me something to work with foo!: ");
	read_line(message, LENGTH);
	copy = duplicate(message);
	strcpy(copy, message);
	printf("your message '%s' and the copy '%s'.", message, copy);

	exit(EXIT_SUCCESS);
}

void read_line (char array[], int size)
{
	char ch = 0;
	int i = 0;

	while (isspace(ch = getchar()))
		;

	while (ch != '\n' && ch != EOF)
	{
		if (i < size)
			array[i++] = ch;
		ch = getchar();
	}

	array[i] = '\0';
}

char *duplicate(char array[])
{
	char *copy = 0;

	copy = malloc(strlen(array) + 1);

	if (copy == NULL)
	{
		printf("Not enough memory");
		exit(EXIT_FAILURE);
	}

	return copy;
}
