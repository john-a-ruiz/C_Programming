/*
	Breaks down ISBN entered by the user
*/

#include <stdio.h>

int main()
{
	int lang = 0, pub = 0, book = 0, check = 0;
	
	printf("\n\n\nEnter ISBN: ");
	scanf("%d- %d- %d- %d", &lang, &pub, &book, &check);
	
	printf("\nLanguage: %d \nPublisher: %d ", lang, pub); 
	printf("\nBook Number: %d\nCheck Digit: %d \n\n\n", book, check);
	
	return 0;
}