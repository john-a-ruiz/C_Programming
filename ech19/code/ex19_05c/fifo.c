/*
 * fifo.c
 *
 *  Created on: Mar 3, 2015
 *      Author: johnruiz
 */

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include "fifo.h"

PRIVATE struct
{
	char *command;
	int (*function)(struct Fifo **q);
} command_list[] =
	{
		{"insert",	insert},
		{"delete",	delete},
		{"first",	first},
		{"last",	last},
		{"empty", 	empty}
	};

PUBLIC int insert(struct Fifo **q)
{
	struct Fifo *new_node;

	new_node = malloc(sizeof(struct Fifo));
	if (new_node == NULL)
	{
		printf("Error in insert; WTF Stupid!!");
		return (EXIT_FAILURE);
	}

	printf("Gimme something exciting son: ");
	scanf("%d", &new_node->data);

	new_node->next = *q;
	*q = new_node;

	return 0;
}
PUBLIC int delete(struct Fifo **q)
{
	struct Fifo *dodo = *q;

	if (dodo == NULL)
	{
		printf("The FIFO is empty!!! STOOOOOOOOOOOOP!!");
		return 0;
	}

	if (dodo->next == NULL)
	{
		*q = dodo->next;
		free (dodo);
		printf("%d no longer exists", dodo->data);
		return 0;
	}

	while (dodo->next != NULL)
		dodo = dodo->next;

	(dodo+1)->next = dodo->next;
	free (dodo);
	printf("%d no longer exists", dodo->data);

	return 0;
}
PUBLIC int first(struct Fifo **q)
{
	struct Fifo *faux = *q;

	if (faux == NULL)
	{
		printf("The FIFO is empty, Stop being lazy and add something!");
		return 0;
	}

	while (faux->next != NULL)
		faux = faux->next;

	printf("%d is the first item in the FIFO", faux->data);

	return 0;
}
PUBLIC int last(struct Fifo **q)
{
	struct Fifo *faux = *q;

	if (faux == NULL)
	{
		printf("The FIFO is empty, Stop being lazy and add something!");
		return 0;
	}

	printf("%d is the last item in the FIFO", faux->data);

	return 0;
}
PUBLIC int empty(struct Fifo **q)
{
	struct Fifo *faux = *q;

	printf("The FIFO %s empty", faux == NULL ? "is" : "is not");

	return 0;
}
PUBLIC void readline(char array[], int size)
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
PUBLIC void execute_command(char array[], struct Fifo **q)
{
	int i;
	char quit[] = {"quit"};

	for (i = 0; i < 5; i++)
	{
		if (strcmp(array, command_list[i].command) == 0)
		{
			command_list[i].function(&*q);
			printf("\n\n");
			return;
		}
	}

	if (strcmp(array, quit) == 0)
	{
		printf("Well I didn't want to fifize with you ANYWAY!!!!");
		return;
	}

	printf("I'm not going to do THAT!!!....sicko.\n\n");
}
