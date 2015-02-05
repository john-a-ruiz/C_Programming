/*
 * modify the 'compare_parts' function so that parts are sorted in descending order
 */

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define LETTERS 10

struct part
{
	char name[LETTERS+1];
	int number;
};

void readline(char array[], int size);
void qsort(void *base, size_t nmemb, size_t size, int (*compar) (const void *, const void *));
int compare_parts(const void *p, const void *q);

int main(void)
{
	int i;
	struct part database[5];

	for (i = 0; i < 5; i++)
	{
		printf("Give me a part name: ");
		readline(database[i].name, LETTERS);

		printf("What is %s's part number: ", database[i].name);
		scanf("%d", &(database[i]).number);
	}

	qsort(database, 5, sizeof(struct part), compare_parts);

	return 0;
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

int compare_parts(const void *p, const void *q)
{
	const struct part *a = p;
	const struct part *b = q;

	if (a->number < b->number)
		return 1;

	if (a->number == b->number)
		return 0;

	if (a->number > b->number)
		return -1;

}
