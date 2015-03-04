/*
 * client.c
 *
 *  Created on: Mar 3, 2015
 *      Author: johnruiz
 */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "fifo.h"

#define SIZE 8

int main(void)
{
	char quit[] = {"quit"};
	char command[SIZE+1] = {0};
	struct Fifo *q = NULL;

	while (strcmp(quit, command) != 0)
	{
		printf("- insert - delete - first - last - empty - quit -\n"
			   "Enter a command for me to perform: ");
		readline(command, SIZE);

		execute_command(command, &q);
	}

	printf("Well I didn't want to play with you anymore ANYWAY!!");

	return (EXIT_SUCCESS);
}
