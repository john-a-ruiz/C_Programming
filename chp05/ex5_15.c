/*
	enter a 2 digit number then print number in english
*/

#include <stdio.h>

int main()
{
	int tens, ones;
	tens = ones = 0;
	
	printf("\n\nEnter a two-digit number: ");
	scanf("%1d%1d", &tens, &ones);
	
	printf("You entered the number: ");
	
	if (tens > 1)
	{
		switch (tens)
		{
			case 9: printf("ninety"); break;
			case 8: printf("eighty"); break;
			case 7: printf("seventy"); break;
			case 6: printf("sixty"); break;
			case 5: printf("fifty"); break;
			case 4: printf("forty"); break;
			case 3: printf("thirty"); break;
			case 2: printf("twenty"); break;
			default: printf("tens-WTF!!"); break;
		}
		
		switch (ones)
		{
			case 9: printf("-nine"); break;
			case 8: printf("-eight"); break;
			case 7: printf("-seven"); break;
			case 6: printf("-six"); break;
			case 5: printf("-five"); break;
			case 4: printf("-four"); break;
			case 3: printf("-three"); break;
			case 2: printf("-two"); break;
			case 1: printf("-one"); break;
			case 0: break;
			default: printf("ones-WTF!!"); break;
		}
		
		printf("\n\n");
		return 0;
	}	
	
	switch (ones)
	{
		case 0: printf("ten"); break;
		case 1: printf("eleven"); break;
		case 2: printf("twelve"); break;
		case 3: printf("thirteen"); break;
		case 4: printf("fourteen"); break;
		case 5: printf("fifteen"); break;
		case 6: printf("sixteen"); break;
		case 7: printf("seventeen"); break;
		case 8: printf("eighteen"); break;
		case 9: printf("nineteen"); break;
		default: printf("one2-WTF!!"); break;
	}
	
	printf("\n\n");
	return 0;
}	