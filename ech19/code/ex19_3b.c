/*
 * A linked-list implementation of the queue module described in exercise 1
 */

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define PUBLIC // empty
#define PRIVATE static
#define SIZE 10

PUBLIC int insert(void);
PUBLIC int delete(void);
PUBLIC int first(void);
PUBLIC int last(void);
PUBLIC int empty(void);
PRIVATE void execute_command(char array[]);
PRIVATE void readline(char array[], int size);

PRIVATE struct node
{
	int data;
	struct node *next;
};

PRIVATE struct
{
	char *command;
	int (*function)(void);
} command_list[] =
	{
		{"insert",	insert},
		{"delete",	delete},
		{"first", 	first},
		{"last", 	last},
		{"empty", 	empty}
	};

PRIVATE struct node *Top = NULL;

int main(void)
{
	char command[SIZE+1] = {0};
	char quit[] = "quit";

	while (strcmp(command, quit) != 0)
	{
		printf("- insert - delete - first - last - empty - quit -\n"
			   "What would you like to do with the FIFO: ");

		readline(command, SIZE);
		execute_command(command);
	}

	printf("\nWe're done here!");
	return (EXIT_SUCCESS);
}

void readline(char array[], int size)
{
	char ch = 0;
	int i = 0;

	while (isspace(ch = getchar()))
		;

	while ((ch != '\n') && (ch != EOF))
	{
		if (i < size)
			array[i++] = ch;

		ch = getchar();
	}

	array[i] = '\0';
}

PRIVATE void execute_command(char array[])
{
	int i;
	int equal = 0;

	for (i = 0; i < 5; i++)
	{
		equal = strcmp(array, command_list[i].command);
		if (equal == 0)
		{
			command_list[i].function();
			printf("\n\n");
			return;
		}
	}

	printf("I am NOT going to do that....sicko..\n\n");
}
PUBLIC int insert(void)
{
	struct node *new_node;

	new_node = malloc(sizeof(struct node));

	if (new_node == NULL)
	{
		printf("Error in 'insert', memory full");
		exit (EXIT_FAILURE);
	}

	printf("What value would you like to insert: ");
	scanf("%d", &new_node->data);
	new_node->next = Top;
	Top = new_node;

	return 0;
}
PUBLIC int delete(void)
{
	struct node *gonner;

	if (Top == NULL)
	{
		printf("The FIFO is empty, already!!");
		return 0;
	}

	if (Top->next == NULL)
	{
		Top = NULL;
		return 0;
	}

	for (gonner = Top; gonner->next != NULL; gonner = gonner->next)
		;

	(gonner+1)->next = gonner->next;
	printf("%d is now deleted", gonner->data);
	free(gonner);

	return 0;
}
PUBLIC int first(void)
{
	struct node *first;

	if (Top == NULL)
	{
		printf("The FIFO is empty");
		return 0;
	}

	for (first = Top; first->next != NULL; first = first->next)
		;

	printf("The first value in the FIFO is %d", first->data);

	return 0;
}
PUBLIC int last(void)
{
	if (Top == NULL)
	{
		printf("The FIFO is empty");
		return 0;
	}

	printf("The last value in the FIFO is %d", Top->data);
	return 0;
}
PUBLIC int empty(void)
{
	if (Top == NULL)
		printf("The FIFO is empty.");
	else
		printf("The FIFO is not empty.");

	return 0;
}
















































