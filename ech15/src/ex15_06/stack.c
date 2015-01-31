/*
 * definitions of functions that manipulate the stack
 */

#include "stack.h"
#include <stdio.h>

int contents[100] = {0};
int top = 0;

void make_empty(void)
{
	top = 0;
}

int is_empty(void)
{
	return (top == 0);
}

int is_full(void)
{
	return (top == 100);
}

void push(int i)
{
	if (top == 100)
		printf("\n\nStack is Full\n\n");
	else
		contents[top++] = i;
}

int pop(void)
{
	if (top == 0)
	{
		printf("\n\nStack is Empty\n\n");
		return 0;
	}
	else
		return contents[--top];
}

int answer(void)
{
	return contents[top-1];
}

void read_line(char array[], int size)
{
	char ch = '0';
	int i = 0;

	while ((ch = getchar()) == ' ')
		;
	array[i++] = ch;

	while (((ch = getchar()) != '\n') && (i < size))
		array[i++] = ch;

	array[i] = '\0';
}

char *next_token(char *element)
{
	while (*element != ' ')
		if (*element == '\0')
			return element;
		else
			element++;

	return (element + 1);
}
