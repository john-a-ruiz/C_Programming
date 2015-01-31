/*
 * search for country code name (user input) in array. If found print dialing code, if not found
 * print error.
 */

#include <stdio.h>
#include <string.h>

#define LETTERS 20

struct dialing_code
{
	char *country;
	int code;
};

void readline(char array[], int size);
void find_code(struct dialing_code array[], char country[]);

int main(void)
{
	const struct dialing_code country_codes[] =
		   {{"Argentina",			54}, {"Bangladesh", 			880},
			{"Brazil",				55}, {"China",					 86},
			{"Colombia",			57}, {"Egypt",					 20},
			{"Ethiopia",		   251}, {"France",					 33},
			{"Germany",				49}, {"India",					 91},
			{"Indonesia",			62}, {"Iran",					 98},
			{"Italy",				39}, {"Japan",					 81},
			{"Korea, Republic of", 	82}, {"Mexico",					 52},
			{"Nigeria",			   234}, {"Pakistan",				 92},
			{"Phillippines",		63}, {"Poland",					 48},
			{"Russia",				 7}, {"South Africa",			 27},
			{"Spain",				34}, {"Thailand",				 66},
			{"Turkey",				90}, {"Ukraine",				  7},
			{"United Kingdom",		44}, {"Vietnam",				 84},
			{"Zaire",			   243}};
	char country[LETTERS+1] = {0};

	while (1)
	{
		printf("Enter the name of a country (* to quit): ");
		readline(country, LETTERS);

		if (country[0] == '*')
			return 0;

		find_code(country_codes, country);
	}
}

void readline(char array[], int size)
{
	int ch = 0, i = 0;

	while ((ch = getchar()) == ' ')
		;
	array[i++] = ch;

	while (((ch = getchar()) != '\n') && (i < size))
		array[i++] = ch;

	array[i] = '\0';
}

void find_code(struct dialing_code array[], char country[])
{
	int i, j;

	for (i = 0; i < 29; i++)										// searching through countries
		for (j = 0; array[i].country[j] == country[j] ; j++)		// checking to see if arrays match
			if (country[j] == '\0')
			{
				printf("The country code for %s is %d.\n\n", array[i].country, array[i].code);
				return;
			}

	printf("I'm sorry I don't have that code :(\n\n");
	return;
}


























