/*
 * write and array based implementation of the queue module described in ex 1
 */

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define PUBLIC // empty
#define PRIVATE static
#define Q_SIZE 10
#define LENGTH 20

// should be placed in a header file
void insert(void);
void delete(void);
void first(void);
void last(void);
void empty(void);

struct
{
	char *command;
	void (*function)(void);
} command_list[] =
	{
		{"insert",	insert},
		{"delete",	delete},
		{"first",	first},
		{"last",	last},
		{"empty", 	empty}
	};

void readline(char array[], int size);
void clearline(char array[], int size);
void execute_command(char array[]);

int q[Q_SIZE] = {0};
int head = 0;
int tail = 0;

int main(void)
{
	char command[LENGTH+1] = {0};
	char quit[] = {"quit"};

	while (strcmp(command, quit) != 0)
	{
		printf("- insert - delete - first - last - empty - quit -\n"
			   "Enter a command for me to perform: ");

		readline(command, LENGTH);
		execute_command(command);
	}

	return (EXIT_SUCCESS);
}

void clearline(char array[], int size)
{
	int i;

	for (i = 0; i < size; i++)
		array[i] = '\0';
}

void readline(char array[], int size)
{
	char ch = 0;
	int i = 0;

	clearline(array, size);

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

void execute_command(char array[])
{
	int i;

	for (i = 0; i < 5; i++)
	{
		if (strcmp(array, command_list[i].command) == 0)
		{
			command_list[i].function();
			printf("\n\n");
			return;
		}
	}

	printf("I am NOT going to do THAT!!!! sicko\n\n\n");
}

void insert(void)
{
	if (tail == Q_SIZE)
	{
		printf("The FIFO is full, please delete item from beginning of FIFO\n");
		return;
	}

	printf("Enter a number for me to insert into the FIFO: ");
	scanf("%d", &q[tail++]);
}
void delete(void)
{
	int i;

	for (i = head; i < (tail-1); i++)
	{
		q[i] = q[i+1];
	}

	tail--;
	q[tail] = 0;
}
void first(void)
{
	printf("The first element in the FIFO is %d", q[head]);
}
void last(void)
{
	printf("The last element in the FIFO is %d", q[tail-1]);
}
void empty(void)
{
	if (head == tail)
		printf("The FIFO is empty\n");
	else
		printf("Ya gots space in da FIFO\n");
}
