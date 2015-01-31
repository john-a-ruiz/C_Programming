/*
	converts numerical grade into a letter grade
*/

#include <stdio.h>

int main()
{
	int grade, tens_digit;
	grade = tens_digit = 0;
	
	printf("\n\nEnter numerical grade: ");
	scanf("%d", &grade);
	
	// error check
	if (grade < 0 || grade > 100)
	{
		printf("LIAR!!!!!! \n\n");
		return 0;
	}
	
	tens_digit = grade / 10;
	
	printf("Letter grade: ");
	switch (tens_digit)
	{
		case 10: case 9: printf("A"); break;
		case 8: printf("B"); break;
		case 7: printf("C"); break;
		case 6: printf("D"); break;
		default: printf("F"); break;
	}
	
	printf("\n\n");
	
	return 0;
}