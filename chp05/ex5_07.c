/*
	calculates a broker's commission
*/

#include <stdio.h>

int main()
{
	float commission, commissionX, value, share_number, share_price;
	commission = commissionX = value = share_number = share_price = 0;
	
	printf("\n\nEnter number of shares: ");
	scanf("%f", &share_number);
	
	printf("Enter price per share: ");
	scanf("%f", &share_price);
	
	value = share_number * share_price;
	
	// our commission
	if (value < 2500.00)
		commission = 30.00 + .017 * value;
	else if (value < 6250.00)
		commission = 56.00 + .0066 * value;
	else if (value < 20000.00)
		commission = 76.00 + .0034 * value;
	else if (value < 50000.00)
		commission = 100.00 + .0022 * value;
	else if (value < 500000.00)
		commission = 155.00 + .0011 * value;
	else 
		commission = 255.00 + .0009 * value;
		
	if (commission < 39.00)
		commission = 39.00;
		
	// their commission
	if (share_number < 2000)
		commissionX = 33.00 + share_number * .03;
	else
		commissionX = 33.00 + share_number * .02;
	
	printf("\nOur commission: $%.2f \n", commission);
	printf("Their commission: $%.2f \n\n", commissionX);
	
	return 0;
}