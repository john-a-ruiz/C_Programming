/*
 * Using a Stack 'type' we can have as many stacks as we want but we sacrifice information hiding
 * so the user can now muck up our shizat.
 * this is a stack client using linked list.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "stack_b.h"

int main(void)
{
	char command = 0;
	int data = 0;
	struct stack *numbers = NULL;

	while (command != 'q')
	{
		printf("p - push, o - pop, e - empty the stack, c - check if empty, q - quit\n"
				"Choose. But choose wisely: ");
		scanf(" %c", &command);

		switch (command)
		{
			case 'p':
				printf("Please enter some data to stack: ");
				scanf("%d", &data);
				push(&numbers, data);
				printf("%d has been pushed.\n\n", numbers->data);
				break;
			case 'o':
				printf("%d has been popped.\n\n", pop(&numbers));
				break;
			case 'e':
				make_empty(&numbers);
				printf("The stack....is now empty.\n\n");
				break;
			case 'c':
				printf("The stack %s empty.\n\n", is_empty(numbers) ? "is" : "is not");
				break;
			case 'q':
				printf("Well I didn't wanna play with ya anymore Anyway!!!");
				return (EXIT_SUCCESS);
			default:
				printf("Im not going to do THAT!!!.....sicko!\n\n");
				break;
		}
	}

	return (EXIT_SUCCESS);
}
