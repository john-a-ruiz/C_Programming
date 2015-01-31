/*
 * modify delete_from_list function so that first argument is type struct node ** and return type is void.
 * it must modify its first argument to point to the list after the desired node has been deleted.
 */

#include <stdio.h>
#include <stdlib.h>

struct node
{
	int value;
	struct node *next;
};

struct node *add_to_list(struct node *list, int n);
void delete_from_list(struct node **list, int n);

int main(void)
{
	struct node *list = NULL;
	char code = 0;
	int value = 0;

	while (code != 'q')
	{
		printf("a-add to list, d-delete from list, q-quit \nPlease choose one: ");
		scanf(" %c", &code);

		switch (code)
		{
			case 'a':
				printf("Give me a value to add: ");
				scanf("%d", &value);
				list = add_to_list(list, value);
				break;
			case 'd':
				printf("Give me a value to look for and delete: ");
				scanf("%d", &value);
				delete_from_list(&list, value);
				break;
			default:
				printf("Incorrect code!\n\n");
		}
	}

	exit(EXIT_SUCCESS);
}

struct node *add_to_list(struct node *list, int n)
{
	struct node *new_node;

	new_node = malloc(sizeof(struct node));
	if (new_node == NULL)
	{
		printf("Malloc failed in add_to_list -- no memory left\n\n");
		exit(EXIT_FAILURE);
	}

	new_node->value = n;
	new_node->next = list;

	return new_node;
}

void delete_from_list(struct node **list, int n)
{
	struct node *cur;


	// searching through list to find n
	for (cur = *list; (cur != NULL) && (cur->value != n); cur = cur->next)
		;

	if (cur == NULL)	// the empty list case
		return;

	(cur+1)->next = cur->next;
	free(cur);
}













































