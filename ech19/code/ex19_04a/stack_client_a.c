/*
 * a client for the interface and implementation of a Stack type using an array
 */

#include <stdio.h>
#include <stdlib.h>
#include "stack.h"

int main(void)
{
	Stack info; make_empty(&info);
	char command = 0;
	int data = 0;

	while (command != 'q')
	{
		printf("p - push, o - pop, e - empty the stack, c - check if empty, q - quit\n"
				"Choose. But choose wisely: ");
		scanf(" %c", &command);

		switch (command)
		{
			case 'p':
				printf("What do you want me to push: ");
				scanf("%d", &data);
				push(&info, data);
				break;
			default:
				printf("no, no, No, NO, NOOOOOOO!!!!....Stupid\n");
		}
	}

	return 0;
}
