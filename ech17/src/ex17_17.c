/*
 * write a function that when given a string as its argument, searches an array of structures for
 * a matching command name, then calls the function associated with that name.
 */

#include <stdio.h>
#include <ctype.h>
#include <string.h>

#define LEN	20

void new_cmd(void);
void open_cmd(void);
void close_cmd(void);
void close_all_cmd(void);
void save_cmd(void);
void save_as_cmd(void);
void save_all_cmd(void);
void print_cmd(void);
void exit_cmd(void);

struct
{
	char *cmd_name;
	void (*cmd_pointer)(void);
} file_cmd[] =
	   {{"new",			new_cmd},
		{"open",		open_cmd},
		{"close",		close_cmd},
		{"close all", 	close_all_cmd},
		{"save",		save_cmd},
		{"save as",		save_as_cmd},
		{"save all",	save_all_cmd},
		{"print",		print_cmd},
		{"exit",		exit_cmd}
	   };


void readline(char array[], int size);
void goto_command(char array[]);

int main(void)
{
	char command[LEN+1] = {0};

	printf("What would you like to do: ");
	readline(command, LEN);

	goto_command(command);

	return 0;
}


void new_cmd(void)
{
	printf("New Command\n");
}
void open_cmd(void)
{
	printf("Open Command\n");
}
void close_cmd(void)
{
	printf("Close Command\n");
}
void close_all_cmd(void)
{
	printf("Close All Command\n");
}
void save_cmd(void)
{
	printf("Save Command\n");
}
void save_as_cmd(void)
{
	printf("Save As Command\n");
}
void save_all_cmd(void)
{
	printf("Save All Command\n");
}
void print_cmd(void)
{
	printf("Print Command\n");
}
void exit_cmd(void)
{
	printf("Exit Command\n");
}

void readline(char array[], int size)
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
}

void goto_command(char array[])
{
	int i;

	for (i = 0; i < 9; i++)
		if (strcmp(array, file_cmd[i].cmd_name) == 0)
		{
			file_cmd[i].cmd_pointer();
			return;
		}

	printf("I'm sorry that is NOT an option\n");
}


































