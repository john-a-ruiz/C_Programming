/*
 * client.c
 *
 *  Created on: Feb 26, 2015
 *      Author: johnruiz
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "fifo.h"

#define LENGTH 8

int main(void)
{
	char command[LENGTH+1] = {0};
	char quit[] = {"quit"};
	Fifo que;
	Fifo *p_que = &que;
	clear(&p_que);

	while (strcmp(command, quit) != 0)
	{
		printf("- insert - delete - first - last - empty - quit -\n"
			   "Enter a command for me to perform: ");
		readline(command, LENGTH);

		execute_command(command, &p_que);
	}

	return 0;
}
