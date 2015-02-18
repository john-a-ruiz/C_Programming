/*
 * using a linked list to implement the stack
 */

#include <stdio.h>
#include <stdlib.h>
#include "stack.h"

struct node
{
	int data;
	struct node *next;
};

static struct node *top = NULL;

void make_empty(void)
{
	top = NULL;
}

int is_emtpy(void)
{
	return top == NULL;
}

void push(int i)
{
	struct node *new_node;

	new_node = malloc(sizeof(struct node));

	if (new_node == NULL)
	{
		printf("Error in push: stack is full.\n");
		exit (EXIT_FAILURE);
	}

	new_node->data = i;
	new_node->next = top;
	top = new_node;
}

int pop(void)
{
	struct node *old_top;
	int i;

	if (is_empty())
	{
		printf("Error in pop; Stack is empty.\n");
		exit (EXIT_FAILURE);
	}

	old_top = top;
	i = top->data;
	top = top->next;
	free(old_top);

	return i;
}
