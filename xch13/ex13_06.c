/*
 *  ex13_6.c
 *  xch13
 *
 *	write a censor function to replace 'foo' with 'xxx'
 */

#include <stdio.h>
#include <string.h>

#define LENGTH 20

int read_line(char array[], int size);
void censor(char array[]);

int main()
{
	char sentence[LENGTH+1] = {'0'};
//	char *p_letter = &sentence[0];
	int length = 0;
	
	printf("\n\nType me a sentence so I can censor it: ");
	length = read_line(sentence, LENGTH);
	
	censor(sentence);
	
	printf("\nThe newly censored sentence now reads:\n%s\n\n", sentence);
	
	return 0;
}

int read_line(char array[], int size)
{
	char ch = '0';
	int i = 0;
	
	while ((ch = getchar()) == ' ');
	array[i++] = ch;
	
	while (((ch = getchar()) != '\n') && (i < size))
		array[i++] = ch;
	
	array[i] = '\0';
	
	return i;
}

void censor(char array[])
{
	char *p_letter = &array[0];
	
	for ( ; *p_letter != '\0'; p_letter++)
	{
		if ((*p_letter == 'f') || (*p_letter == 'F'))
			if ((*(p_letter+1) == 'o') || (*(p_letter+1) == 'O'))
				if ((*(p_letter+2) == 'o') || (*(p_letter+2) == 'O'))
				{
					*p_letter = 'x';
					*(p_letter+1) = 'x';
					*(p_letter+2) = 'x';
				}
	}
}