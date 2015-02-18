/*
 * using an array to implement the stack
 */

#include <stdio.h>
#include <stdlib.h>
#include "stack.h"

#define STACK_SIZE 100

static int contents[STACK_SIZE];
static int top = 0;

void make_empty(void)
{
	top = 0;
}

int is_empty(void)
{
	return top == 0;
}

static int is_full(void)
{
	return top == STACK_SIZE;
}

void push(int i)
{
	if (is_full())
	{
		printf("Error in push: stack is ful.\n");
		exit (EXIT_FAILURE);
	}

	contents[top++];
}

int pop(void)
{
	if (is_empty())
	{
		printf("Error in pop: stack is empty.\n");
		exit (EXIT_FAILURE);
	}

	return contents[--top];
}
