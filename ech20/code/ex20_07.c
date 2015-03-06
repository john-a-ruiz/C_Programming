/*
 * write two functions that take a hex value and rotate it in either direction x times.
 */

#include <stdio.h>
#include <ctype.h>
#include <string.h>

#define SIZE 5

void readline(char array[], int size);
unsigned int rotate_left(unsigned int i, int n);
unsigned int rotate_right(unsigned int i, int n);

int main(void)
{
	unsigned int rotation = 0;
	unsigned int post = 0;
	int number = 0;
	char spin[5+1] = {0};
	char right[] = {"right"};

	printf("Gimme a 16bit hex number son (0xHHHH): ");
	scanf("0x%4X", & rotation);

	printf("right or left? ");
	readline(spin, SIZE);

	printf("How many times to the %s? ", spin);
	scanf("%d", &number);

	if (strcmp(spin, right) == 0)
		post = rotate_right(rotation, number);
	else
		post = rotate_left(rotation, number);

	printf("\nYour precious little 0x%X has now become 0x%X\n"
			"I hope you like it.... HAA HAA HAAAA HA HA!!!", rotation, post);

	return 0;
}

void readline(char array[], int size)
{
	char ch = 0;
	int i = 0;

	while (isspace(ch = getchar()))
		;

	while ((ch != '\n') && (ch != EOF))
	{
		if (i < size)
			array[i++] = ch;
		ch = getchar();
	}

	array[i] = '\0';
}

unsigned int rotate_left(unsigned int i, int n)
{
	unsigned int byte = 0;
	int x;

	for (x = 0; x < n; x++)
	{
		byte = (0xF000 & i);
		i = (0x0FFF & i);
		i = (i << 4) | (byte >> 12);
	}

	return i;
}
unsigned int rotate_right(unsigned int i, int n)
{
	unsigned int byte = 0;
	int x;

	for (x = 0; x < n; x++)
	{
		byte = (0x000F & i);
		i = (i >> 4) | (byte << 12);
	}

	return i;
}




































