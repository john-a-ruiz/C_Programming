/*
 *  ex13_14.c
 *  xch13
 *
 *	find the smallest and largest in a series of words
 */

#include <stdio.h>
#include <string.h>

#define LETTER 20

int main()
{
	char word[LETTER+1] = {'\0'};
	char small_word[LETTER+1] = "|";
	char large_word[LETTER+1] = {' '};
	int word_len = 0;
	
	printf("\n\nUse a four letter word to terminate\n");
	while (word_len != 4)
	{
		printf("Enter a word (<20 char): ");
		scanf("%20s", word);
		word_len = strlen(word);
		
		if (strcmp(word, small_word) < 0)
			strcpy(small_word, word);
			
		if (strcmp(word, large_word) > 0)
			strcpy(large_word, word);
	}
	
	printf("\n\nThe smallest word is: %s", small_word);
	printf("\nThe largest word is: %s\n\n", large_word);
	return 0;
}
		  
