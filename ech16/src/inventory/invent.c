/*
 * Maintains a parts database (array version)
 *
 * modified to include a price
 */

#include <stdio.h>
#include "readline.h"

#define NAME_LEN 25
#define MAX_PARTS 100

struct part
{
	int number;
	char name[NAME_LEN+1];
	int on_hand;
	float price;
} inventory[MAX_PARTS];

int num_parts = 0;		// number of parts currently stored

int find_part(int number);
void insert(void);
void search(void);
void update(void);
void cost(void);
void print(void);

/*
 * main:	Prompts the user to enter an operation code, then calls a function to perform the
 * 			requested action. Repeats until the user enters the command 'q'. Prints an
 * 			error message if the user enters an illegal code.
 */
int main(void)
{
	char code;

	for (;;)
	{

		scanf(" %c", &code);
		while (getchar() != '\n')
			;

		switch (code)
		{
			case 'i':
				insert();
				break;
			case 's':
				search();
				break;
			case 'u':
				update();
				break;
			case 'p':
				print();
				break;
			case '$':
				cost();
				break;
			case 'q':
				return 0;
			default:
				printf("Illegal code\n");
		}
		printf("\n");
	}
}

/*
 * find_part:	Looks up a part number in the inventory array. Returns the array index
 * 				if the part number is found; otherwise, return -1.
 */
int find_part(int number)
{
	int i;

	for (i = 0; i < num_parts; i++)
		if (inventory[i].number == number)
			return i;

	return -1;
}

/*
 * insert:	Prompts the user for information about a new part and then inserts the part
 * 			into the database. Prints and error message and returns prematurely if the part
 * 			already exists or the database is full.
 */
void insert(void)
{
	int part_number;

	if (num_parts == MAX_PARTS)
	{
		printf("Database is full; can't add more parts.\n");
		return;
	}

	printf("Enter part number: ");
	scanf("%d", &part_number);

	if (find_part(part_number) >= 0)
	{
		printf("Part already exists.\n");
		return;
	}

	inventory[num_parts].number = part_number;
	printf("Enter part name: ");
	read_line(inventory[num_parts].name, NAME_LEN);

	printf("Enter part price: ");
	scanf("%f", &inventory[num_parts].price);

	printf("Enter quantity on hand: ");
	scanf("%d", &inventory[num_parts].on_hand);
	num_parts++;
}

/*
 * search:	Prompts the user to enter a part number, then looks up the part in the database.
 * 			If the part exists, prints the name and quantity on hand; if not, prints the
 * 			error message.
 */
void search(void)
{
	int i, number;

	printf("Enter part number: ");
	scanf("%d", &number);
	i = find_part(number);

	if (i >= 0)
	{
		printf("Part name: %s\n", inventory[i].name);
		printf("Part price: $%f\n", inventory[i].price);
		printf("Quantity on hand: %d\n", inventory[i].on_hand);
	}
	else
		printf("Part not found.\n");
}

/*
 * update:	Prompts the uset to enter a part number. Prints an error message if the part
 * 			doesn't exist; otherwise, prompts the user to enter change in quantity on hand
 * 			and update the database
 */
void update(void)
{
	int i, number, change;

	printf("Enter part number: ");
	scanf("%d", &number);

	i = find_part(number);

	if (i >= 0)
	{
		printf("Enter change in quantity on hand: ");
		scanf("%d", &change);
		inventory[i].on_hand += change;
	}
	else
		printf("Part not found");
}

/*
 * cost:	Prompts the user to enter a part number. Prints an error message if the part
 * 			doesn't exist; otherwise, prompts the user to enter change in price
 * 			and update the database
 */
void cost(void)
{
	int i, number;
	float change;

	printf("Enter part number: ");
	scanf("%d", &number);

	i = find_part(number);

	if (i >= 0)
	{
		printf("Enter change in price: ");
		scanf("%f", &change);
		inventory[i].price += change;
	}
	else
		printf("Part not found");
}

/*
 * print:	Prints a listing of all parts in the database, showing the part number, part name,
 * 			and quantity on hand. Parts are printed in the order in which ther were entered
 * 			into the database.
 */

/*
 *  modified to print in part number order
 */
void print(void)
{
	int i, j, smallest, delete;
	struct part ordered[MAX_PARTS];

	for (i = 0, smallest = 65000; i < num_parts; i++)
	{
		for (j = 0; j < num_parts; j++)
		{
			if (inventory[j].number <= smallest)
			{
				smallest = inventory[j].number;
				delete = j;
				ordered[i] = inventory[j];
			}
		}
		inventory[delete].number = 65001;
		smallest = 65000;
	}

	for (i = 0; i < num_parts; i++)
		inventory[i] = ordered[i];

	printf("Part Number \t Part Price \t Part Name \t\t Quantity on hand\n");
	for (i = 0; i < num_parts; i++)
		printf("%7d \t %7.2f \t %-25s %7d\n", inventory[i].number, inventory[i].price,
				inventory[i].name, inventory[i].on_hand);
}
