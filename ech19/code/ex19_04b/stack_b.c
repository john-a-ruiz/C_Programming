/*
 * Using a stack 'type' we can have as many stacks as we want but we sacrifice information hiding
 * so the user can now muck up our shizat.
 * this is a stack implementation using linked list.
 */

#include <stdio.h>
#include <stdlib.h>
#include "stack_b.h"

PUBLIC void make_empty(struct stack **s)
{
	struct stack *old_node;

	while (*s != NULL)
	{
		old_node = *s;
		*s = old_node->next;
		free (old_node);
	}
}
PUBLIC int is_empty(const struct stack *s)
{
	return (s == NULL);
}
PUBLIC void push(struct stack **s, int i)
{
	struct stack *new_node;

	new_node = malloc(sizeof(struct stack));
	if (new_node == NULL)
	{
		printf("Error in push, stack is full.\nBye");
		exit (EXIT_FAILURE);
	}

	new_node->data = i;
	new_node->next = *s;
	*s = new_node;
}
PUBLIC int pop(struct stack **s)
{
	struct stack *old_node;
	int i;

	if (is_empty(*s))
	{
		printf("Error in pop, stack is empty.\nBye");
		exit (EXIT_FAILURE);
	}

	old_node = *s;
	i = old_node->data;
	*s = old_node->next;
	free (old_node);

	return i;
}
