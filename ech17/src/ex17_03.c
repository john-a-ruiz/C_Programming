/*
 * the user enters a series of words. then program sorts words alphabetically and removes any duplicates
 */

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define W_LENGTH 10
#define A_LENGTH 4
#define TRUE 1
#define FALSE 0

int read_line(char array[], int size);
void *my_malloc(char array[], char *spot);
void sort(char *array[], int size);

int main(void)
{
	char word[W_LENGTH+1] = {0};
	char *list[A_LENGTH] = {0};
	int another = TRUE, i = 0;

	while (another == TRUE && list[A_LENGTH-1] == 0)
	{
		printf("Enter Word ($ to quit): ");
		another = read_line(word, W_LENGTH);
		list[i] = my_malloc(word, list[i]);
		i++;
	}

	sort(list, i);

	exit(EXIT_SUCCESS);
}

int read_line(char array[], int size)
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

	if (array[0] == '$')
		return FALSE;

	return TRUE;
}
void *my_malloc(char array[], char *spot)
{
	spot = malloc(strlen(array+1));

	if (spot == NULL)
	{
		printf("No more memory");
		exit(EXIT_FAILURE);
	}

	strcpy(spot, array);
	return spot;
}
void sort(char *array[], int size)   // just not getting how to sort an array of pointers.
{
	char *sorted[A_LENGTH] = {0};
	char *small = array[0];
	int i = 0, j = 0;

	for (i = 0; i < size; i++)
	{
		for (j = 0; j < size; j++)
		{
			if (strcmp(small, array[j]) < 0)
				strcpy(small, array[j]);
		}
		sorted[i] = small;
		array[i] = array[i+1];
	}
}
