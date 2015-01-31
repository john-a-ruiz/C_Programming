/*
	checks whether an airline ticket is valid
*/

#include <stdio.h>

int main()
{
	char ticket = 0;
	int remainder, number, check, flag;
	remainder = number = check = flag = 0;
	
	printf("\n\nEnter ticket number: ");
	while ((ticket = getchar()) != '\n')
	{
		//turn character into integer digit
		if (ticket == '0')
			number = 0;
		else if (ticket == '1')
			number = 1;
		else if (ticket == '2')
			number = 2;
		else if (ticket == '3')
			number = 3;
		else if (ticket == '4')
			number = 4;
		else if (ticket == '5')
			number = 5;
		else if (ticket == '6')
			number = 6;
		else if (ticket == '7')
			number = 7;
		else if (ticket == '8')
			number = 8;
		else if (ticket == '9')
			number = 9;
		else
			printf("ERROR\n"); break;
		
		if (check == number)
			flag = 1;
		else
			flag = 0;
		
		remainder += number;
		remainder %= 7;
		check = remainder;
		// get remainder ready for next division
		remainder *= 10;
	}
	
	if (flag == 1)
		printf("Valid");
	else
		printf("Not Valid");
	
	printf("\n\n");
	return 0;
}