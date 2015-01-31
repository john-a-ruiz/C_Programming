/*
	translates an alphabetic phone number (upper case) into numeric form
*/

#include <stdio.h>

int main()
{
	char number;
	number = 0;
	
	printf("\n\nEnter phone number: ");
	while ((number = getchar()) != '\n')
	{
		if (65 <= number && number <= 67) //ABC
			putchar('2');
		else if (68 <= number && number <= 70) //DEF
			putchar('3');
		else if (71 <= number && number <= 73) //GHI
			putchar('4');
		else if (74 <= number && number <= 76) //JKL
			putchar('5');
		else if (77 <= number && number <= 79) //MNO
			putchar('6');
		else if (80 <= number && number <= 83) //PQRS
			putchar('7');
		else if (84 <= number && number <= 86) //TUV
			putchar('8');
		else if (87 <= number && number <= 90) //WXYZ
			putchar('9');
		else
			putchar(number);
	}
		
	printf("\n\n");
	return 0;
}