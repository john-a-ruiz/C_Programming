/*
 * write a wrapper function for malloc. If malloc successful return pointer else print error and terminate.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define LENGTH 40

void read_line(char array[], int size);
char *my_malloc(char array[]);

int main(void)
{
	char message[LENGTH+1] = {0};
	char *message_list[5] = {0};

	printf("Enter a line of text for me to mess with: ");
	read_line(message, LENGTH);
	message_list[0] = my_malloc(message);
	strcpy(message_list[0], message);
	printf("Your message was: %s\n\n", message_list[0]);

	printf("Enter a line of text for me to mess with: ");
	read_line(message, LENGTH);
	message_list[1] = my_malloc(message);
	strcpy(message_list[1], message);
	printf("Your message was: %s\n\n", message_list[1]);

	printf("Enter a line of text for me to mess with: ");
	read_line(message, LENGTH);
	message_list[2] = my_malloc(message);
	strcpy(message_list[2], message);
	printf("Your message was: %s\n\n", message_list[2]);

	exit(EXIT_SUCCESS);
}

void read_line(char array[], int size)
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

char *my_malloc(char array[])
{
	char *line = 0;

	line = malloc(strlen(array) + 1);

	if (line == NULL)
	{
		printf("Not enough memory");
		exit(EXIT_FAILURE);
	}

	return line;
}
