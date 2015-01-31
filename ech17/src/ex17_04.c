/*
 * dynamically allocate an array of structs then reallocate after the array is full
 *
 *
 */

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define N_LENGTH 20

struct part
{
	float price;
	int number;
	char name[N_LENGTH+1];
	int quantity;
};

void read_line(char array[], int size);

int main(void)
{
	struct part *inventory = 0;
	int i = 0,j , size = 0;
	char expand = 0;

	printf("How big do you want the inventory to be: ");
	scanf("%d", &size);

	inventory =  malloc(size * sizeof(struct part));

a:	for ( ; i < size; i++)
	{
		printf("\n\nEnter part name: ");
		read_line((inventory+i)->name, N_LENGTH);

		printf("Enter part price: ");
		scanf("%f", &(inventory+i)->price);

		printf("Enter part number: ");
		scanf("%d", &(inventory+i)->number);

		printf("Enter quantity of parts on hand: ");
		scanf("%d", &(inventory+i)->quantity);
	}

	printf("\nThere is no more room in inventory. \nYour parts are:\n");
	for (j = 0; j < size; j++)
	{
		printf("part %d name: %s\n", j+1, (inventory+j)->name);
	}

	printf("\nWould you like to expand the capacity of the inventory? (y or n): ");
	scanf(" %c", &expand);
/*
 *
 * PROBLEM!!!!!!!! When I realloc more memory the last struct before doubling gets jacked up when printed.
 * Maybe solve later
 *
 */

	if (expand == 'y')
	{
		inventory = realloc(inventory, 2*size);
		size *= 2;
		printf("\nYour inventory capacity has been doubled.\n");
		goto a;
	}

	printf("\n\nOK, Have a nice day.");
	exit(EXIT_SUCCESS);
}

void read_line(char array[], int size)
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












































