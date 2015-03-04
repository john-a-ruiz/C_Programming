/*
 *
 */

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include "fifo.h"

PRIVATE struct
{
	char *command;
	int (*function)(Fifo **q);
} command_list[] =
	{
		{"insert",	insert},
		{"delete",	delete},
		{"first",	first},
		{"last",	last},
		{"empty", 	empty}
	};

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

PUBLIC int insert(Fifo **q)
{
	Fifo *temp = *q;

	if (temp->tail == FIFO_SIZE)
	{
		printf("The fifo is full, come back tomorrow!\n\n");
		return 0;
	}

	printf("Enter a value to fifize: ");
	scanf("%d", &temp->FIFO[temp->tail++]);

	return 0;
}
PUBLIC int delete(Fifo **q)
{
	Fifo *faux = *q;
	int dodo = faux->FIFO[faux->head];
	int i;

	for (i = 0; i < faux->tail; i++)
	{
		faux->FIFO[i] = faux->FIFO[i+1];
	}

	printf("%d has been deleted from the FIFO", dodo);

	return 0;
}
PUBLIC int first(Fifo **q)
{
	Fifo *faux = *q;

	printf("%d is the at the head of the FIFO", faux->FIFO[faux->head]);

	return 0;
}
PUBLIC int last(Fifo **q)
{
	Fifo *faux = *q;

	printf("%d is at the tail of the FIFO", faux->FIFO[faux->tail-1]);

	return 0;
}
PUBLIC int empty(Fifo **q)
{
	Fifo *faux = *q;

	printf("The FIFO %s empty", faux->head == faux->tail ? "is" : "is not");

	return 0;
}
PUBLIC int clear(Fifo **q)
{
	int i;
	Fifo *temp = *q;

	temp->head = 0;
	temp->tail = 0;

	for (i = 0; i < FIFO_SIZE; i++)
		temp->FIFO[i] = 0;

	return 0;
}

PUBLIC void execute_command(char array[], Fifo **q)
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
