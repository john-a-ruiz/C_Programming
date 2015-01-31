/*
 * modify remove2 so that it only uses one pointer vs two (cur and prev)
 * modified version is remove1
 */

#include <stdio.h>
#include <stdlib.h>

struct node
{
	int value;
	struct node *next;
};

struct node *add1(struct node *list, int n);
struct node *remove1(struct node *list, int n);

int main(void)
{
	struct node *linked = NULL;
	char code = 0;
	int value = 0;

	while (code != 'q')
	{
		printf("Would you like to add to 'a' or delete from 'd' the list (q to quit: ");
		scanf(" %c", &code);

		switch (code)
		{
			case 'a':
				printf("Enter value to add: ");
				scanf("%d", &value);
				linked = add1(linked, value);
				break;
			case 'd':
				printf("Enter the value you want to delete: ");
				scanf("%d", &value);
				linked = remove1(linked, value);
				break;
			case 'q':
				exit(EXIT_SUCCESS);
			default:
				printf("wrong character\n");
				break;
		}
	}

	exit(EXIT_SUCCESS);
}

struct node *add1(struct node *list, int n)
{
	struct node *new_node;

	new_node = malloc(sizeof(struct node));
	if (new_node == NULL)
	{
		printf("Error: malloc failed in add_to_list\n");
		exit(EXIT_FAILURE);
	}

	new_node->value = n;
	new_node->next = list;
	return new_node;
}

struct node *remove2(struct node *list, int n)			// uses two pointers
{
	struct node *prev, *cur;

	for (cur = list, prev = NULL;
		 cur != NULL && cur->value != n;
		 prev = cur, cur = cur->next)
		;

	if (cur == NULL)
		return list;
	if (prev == NULL)
		list = list->next;
	else
		prev->next = cur->next;
	free(cur);

	return list;
}

struct node *remove1(struct node *list, int n)			// uses one pointer
{
	struct node *cur;

	for (cur = list; cur != NULL && cur->value != n; cur = cur->next)
		;

	if (cur == NULL)
		return list;
	else
		(cur+1)->next = cur->next;
	free(cur);

	return list;
}







































