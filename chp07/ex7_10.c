/*
	computes the value of a scrabble word by summing the value of its letters
*/

#include <stdio.h>

int main()
{
	char word;
	int value = 0;
	
	printf("\n\nEnter a word: ");
	while ((word = getchar()) != '\n')
	{
		switch (word)
		{
			case 'A': case 'E': case 'I': case 'L': case 'N': 
			case 'O': case 'R': case 'S': case 'T': case 'U':
				value += 1; break;
			
			case 'D': case 'G':
				value += 2; break;
			
			case 'B': case 'C': case 'M': case 'P':
				value += 3; break;
				
			case 'F': case 'H': case 'V': case 'W': case 'Y':
				value += 4; break;
				
			case 'K':
				value += 5; break;
				
			case 'J': case 'X':
				value += 8; break;
				
			case 'Q': case 'Z':
				value += 10; break;
			
			default:
				printf("Error"); break;
		}
	}
	
	printf("Scrabble value: %d \n\n", value);
	
	return 0;
}