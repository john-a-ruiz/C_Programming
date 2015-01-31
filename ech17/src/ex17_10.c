/*
 * implement the stack program in chp 15.2 using a linked list
 */

#include <stdio.h>
#include <stdlib.h>

#define TRUE 1
#define FALSE 0

struct node
{
	int value;
	struct node *next;
};

int push(void);
void pop(void);
void empty(void);

struct node *top = NULL;
struct node *new_node = NULL;

int main(void)
{
	char code;

	while (1)
	{
		printf("p-push, o-pop, e-make empty, q-quit\n");
		printf("What would you like to do: ");
		scanf(" %c", &code);
		while (getchar() != '\n')
			;

		switch (code)
		{
			case 'p':
				if (push() == TRUE)
					printf("%d was pushed successfully!\n\n", top->value);
				else
					printf("not enough memory to push!\n\n");
				break;
			case 'o':
				pop();
				break;
			case 'e':
				empty();
				break;
			case 'q':
				return 0;
			default:
				printf("Illegal code");
		}
	}
}

int push(void)
{
	new_node = malloc(sizeof(struct node));
	if (new_node == NULL)
	{
		printf("MALLOC ERROR\n");
		return FALSE;
	}

	printf("Enter a value to push: ");
	scanf("%d", &new_node->value);
	new_node->next = top;
	top = new_node;

	return TRUE;
}

void pop(void)
{
	if (top == NULL)
	{
		printf("The stack is empty.\n\n");
		return;
	}

	printf("%d has been popped\n\n", top->value);

	new_node = top;
	if (top->next == NULL)
		top = NULL;
	else
		top = top->next;
	free(new_node);
}

void empty(void)
{
	if (top == NULL)
	{
		printf("The stack is empty.\n\n");
		return;
	}

	while (top->next != NULL)
	{
		new_node = top;
		top = top->next;
		free(new_node);
	}

	new_node = top;
	top = NULL;
	free(new_node);

	printf("The stack is empty.\n\n");
}









































