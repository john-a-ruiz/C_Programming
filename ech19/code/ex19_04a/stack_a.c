/*
 * implementation of a Stack type using an array representation.
 */

#include <stdio.h>
#include <stdlib.h>
#include "stack_a.h"

PRIVATE int is_full(Stack *s);
PRIVATE void initialize(Stack *s);

PRIVATE int is_full(Stack *s)
{
	return s->top == STACK_SIZE;
}

PRIVATE void initialize(Stack *s)
{
	int i;

	s->top = 0;
	for (i = 0; i < STACK_SIZE; i++)
		s->contents[i] = 0;
}

PUBLIC void make_empty(Stack *s)
{
	initialize(s);
}
PUBLIC int is_empty(const Stack *s)
{
	return s->top == 0;
}
PUBLIC void push(Stack *s, int i)
{
	if (is_full(s))
	{
		printf("Can't do it!! The stack is full son.\n Bye!!");
		exit (EXIT_FAILURE);
	}

	s->contents[(s->top)++] = i;
}
PUBLIC int pop(Stack *s)
{
	if (is_empty(s))
	{
		printf("Can't do it!! The Stack is empty son.\n Bye!!");
		exit (EXIT_FAILURE);
	}

	return s->contents[--(s->top)];
}

