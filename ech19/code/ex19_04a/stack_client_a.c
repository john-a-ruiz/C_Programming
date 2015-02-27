/*
 * a client for the interface and implementation of a Stack type using an array
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "stack_a.h"

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
				printf("%d has been pushed.\n\n", info.contents[(info.top)-1]);
				break;
			case 'o':
				printf("%d has been popped.\n\n", pop(&info));
				break;
			case 'e':
				make_empty(&info);
				printf("The stack......is now empty.\n\n");
				break;
			case 'c':
				printf("The stack %s empty.\n\n", is_empty(&info) ? "is" : "is not");
				break;
			case 'q':
				printf("Well if you wanna be THAT way!!");
				return 0;
			default:
				printf("no, no, No, NO, NOOOOOOO!!!!....Stupid\n\n");
		}
	}

	return 0;
}
