/*
 * write program similar to invent.c that uses a 'catalog_item' struct to store info
 */

#include <stdio.h>
#include <ctype.h>

#define MAX_ITEMS 10
#define TITLE_LENGTH 20
#define AUTHOR_LENGTH 20
#define DESIGN_LENGTH 20
#define BOOK 0
#define MUG 1
#define SHIRT 2
#define TRUE 1
#define FALSE 0

struct catalog_item
{
	int stock_number;
	float price;
	int item_type;
	union
	{
		struct
		{
			char title[TITLE_LENGTH+1];
			char author[AUTHOR_LENGTH+1];
			int num_pages;
		} book;

		struct
		{
			char design[DESIGN_LENGTH+1];
		} mug;

		struct
		{
			char design[DESIGN_LENGTH+1];
			int colors;
			int sizes;
		} shirt;
	} item;
};

void read_line(char array[], int size);
void insert(struct catalog_item inventory[], int *quantity);
void search(struct catalog_item inventory[], int *quantity);
void update(struct catalog_item inventory[], int *quantity);

int main(void)
{
	struct catalog_item inventory[MAX_ITEMS];
	int quantity = 0;
	int *p_quantity = &quantity;
	char code = 0;

	for(;;)
	{
		printf("Enter inventory operation code (i-insert, s-search, u-update, p-print, q-quit): ");
		scanf(" %c", &code);

		while (getchar() != '\n')
			;

		switch (code)
		{
			case 'i':
				insert(inventory, p_quantity);
				break;
			case 's':
				search(inventory, p_quantity);
				break;
			case 'u':
				update(inventory, p_quantity);
				break;
			case 'p':
				printf("I haven't finished this function yet :)");
				break;
			case 'q':
			default:
				return 0;
		}
		printf("\n\n");
	}
}

void read_line(char array[], int size)
{
	int i = 0;
	char ch = 0;

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
void insert(struct catalog_item inventory[], int *quantity)
{
	char code = 0;

	if (*quantity == MAX_ITEMS)
	{
		printf("Inventory Database is full.\n");
		return;
	}

	printf("What type of item would you like to insert into inventory (b-book, m-mug, s-shirt): ");
	scanf(" %c", &code);

	while (getchar() != '\n')
		;

	switch (code)
	{
		case 'b':
			inventory[*quantity].item_type = BOOK;

			printf("Enter the stock number of the book: ");
			scanf("%d", &inventory[*quantity].stock_number);

			printf("Enter the cost of the book: ");
			scanf("%f", &inventory[*quantity].price);

			printf("Enter the Author of the book: ");
			read_line(inventory[*quantity].item.book.author, AUTHOR_LENGTH);

			printf("Enter the Title of the book: ");
			read_line(inventory[*quantity].item.book.title, TITLE_LENGTH);

			printf("Enter the number of pages: ");
			scanf("%d", &inventory[*quantity].item.book.num_pages);
			break;
		case 'm':
			inventory[*quantity].item_type = MUG;

			printf("Enter the stock number of the mug: ");
			scanf("%d", &inventory[*quantity].stock_number);

			printf("Enter the cost of the mug: ");
			scanf("%f", &inventory[*quantity].price);

			printf("Enter the name of the design on the mug: ");
			read_line(inventory[*quantity].item.mug.design, DESIGN_LENGTH);
			break;
		case 's':
			inventory[*quantity].item_type = SHIRT;

			printf("Enter the stock number of the shirt: ");
			scanf("%d", &inventory[*quantity].stock_number);

			printf("Enter the cost of the shirt: ");
			scanf("%f", &inventory[*quantity].price);

			printf("Enter the name of the design on the shirt: ");
			read_line(inventory[*quantity].item.shirt.design, DESIGN_LENGTH);

			printf("Enter the number of colors of the shirt: ");
			scanf("%d", &inventory[*quantity].item.shirt.colors);

			printf("Enter the number of sizes for the shirt: ");
			scanf("%d", &inventory[*quantity].item.shirt.sizes);
			break;
		default:
			printf("That is not an option.");
			return;
	}

	++*quantity;
}
void search(struct catalog_item inventory[], int *quantity)
{
	int i = 0, exists = 0, item = 0;

	printf("Enter the stock number of the item you are looking for: ");
	scanf("%d", &item);

	for (i = 0, exists = FALSE; i < *quantity; i++)
		if (inventory[i].stock_number == item)
		{
			exists = TRUE;
			break;
		}

	if (exists == FALSE)
	{
		printf("There is no item with that stock number in inventory.");
		return;
	}

	switch (inventory[i].item_type)
	{
		case BOOK:
			printf("Stock Number: %d\n", inventory[i].stock_number);
			printf("Item Type: Book\n");
			printf("Price: %.2f\n", inventory[i].price);
			printf("Book Title: %s\n", inventory[i].item.book.title);
			printf("Book Author: %s\n", inventory[i].item.book.author);
			printf("Number of Pages: %d", inventory[i].item.book.num_pages);
			break;
		case MUG:
			printf("Stock Number: %d\n", inventory[i].stock_number);
			printf("Item Type: Mug\n");
			printf("Price: %.2f\n", inventory[i].price);
			printf("Mug Design: %s\n", inventory[i].item.mug.design);
			break;
		case SHIRT:
			printf("Stock Number: %d\n", inventory[i].stock_number);
			printf("Item Type: Shirt\n");
			printf("Price: %.2f\n", inventory[i].price);
			printf("Shirt Design: %s\n", inventory[i].item.shirt.design);
			printf("Different Shirt Colors: %d", inventory[i].item.shirt.colors);
			printf("Different Shirt Sizes: %d", inventory[i].item.shirt.sizes);
			break;
	}
}
void update(struct catalog_item inventory[], int *quantity)
{
	int i = 0, exists = 0, item = 0;
	char code = 0;

	printf("Enter the stock number of the item you want to update: ");
	scanf("%d", &item);

	for (i = 0, exists = FALSE; i < *quantity; i++)
		if (inventory[i].stock_number == item)
		{
			exists = TRUE;
			break;
		}

	if (exists == FALSE)
	{
		printf("There is no item with that stock number in inventory.");
		return;
	}

	switch (inventory[i].item_type)
	{
		case BOOK:
B_change:	printf("Which parameter would you like to change p-price, t-title, a-author, n-page number: ");
			scanf(" %c", &code);
			switch (code)
			{
				case 'p':
					printf("Enter new price: ");
					scanf("%f", &inventory[i].price);
					break;
				case 't':
					printf("Enter new title: ");
					read_line(inventory[i].item.book.title, TITLE_LENGTH);
					break;
				case 'a':
					printf("Enter new author: ");
					read_line(inventory[i].item.book.author, AUTHOR_LENGTH);
					break;
				case 'n':
					printf("Enter new page count: ");
					scanf("%d", &inventory[i].item.book.num_pages);
					break;
				default:
					printf("Not a valid choice.\n\n");
					goto B_change;
			}
			break;
		case MUG:
M_change:	printf("Which paramter would you like to change: p-price, d-design: ");
			scanf(" %c", &code);
			switch (code)
			{
				case 'p':
					printf("Enter new price: ");
					scanf("%f", &inventory[i].price);
					break;
				case 'd':
					printf("Enter new design name: ");
					read_line(inventory[i].item.mug.design, DESIGN_LENGTH);
					break;
				default:
					printf("Not a valid choice.\n\n");
					goto M_change;
			}
			break;
		case SHIRT:
S_change:	printf("Which parameter would you like to change p-price, d-design, c-colors, s-sizes: ");
			scanf(" %c", &code);
			switch (code)
			{
				case 'p':
					printf("Enter new price: ");
					scanf("%f", &inventory[i].price);
					break;
				case 'd':
					printf("Enter new design name: ");
					read_line(inventory[i].item.shirt.design, DESIGN_LENGTH);
					break;
				case 'c':
					printf("Enter new number of color options: ");
					scanf("%d", &inventory[i].item.shirt.colors);
					break;
				case 's':
					printf("Enter new number of size options: ");
					scanf("%d", &inventory[i].item.shirt.sizes);
					break;
				default:
					goto S_change;
			}
			break;
	}
}





























