/*
	Write an interactive program that formats the input data
*/

#include <stdio.h>

int main()
{
	int number = 0, month = 0, day = 0, year = 0;
	float price = 0;
	
	printf("\n\n\nEnter item number: ");
	scanf("%d", &number);
	
	printf("Enter unit price: ");
	scanf("%f", &price);
	
	printf("Enter purchase date (mm/dd/yy): ");
	scanf("%d/ %d/ %d", &month, &day, &year);
	
	printf("\n\nItem\t\tUnit\t\tPurchase\n");
	printf("    \t\tPrice\t\tDate\n");
	printf("%d\t\t$%6.2f\t\t%.2d/%.2d/%.2d \n\n\n", number, price, month, day, year);
	
	return 0;
}