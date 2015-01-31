/*
	balances a checkbook
*/

#include <stdio.h>

int main()
{
	int cmd = 0;
	float balance, credit, debit;
	balance = credit = debit = 0.0;
	
	printf("\n\nACME checkbook-balancing program\n");
	printf("Commands: 0=clear, 1=credit, 2=debit, 3=balance, 4=exit \n\n");
	
	for (;;)
	{
		printf("Enter Command: ");
		scanf("%d", &cmd);
		
		switch (cmd)
		{
			case 0:
				balance = 0.0;
				break;
			case 1:
				printf("Enter amount of credit: ");
				scanf("%f", &credit);
				balance += credit;
				break;
			case 2:
				printf("Enter amount of debit: ");
				scanf("%f", &debit);
				balance -= debit;
				break;
			case 3:
				printf("Current balance: $%.2f", balance);
				break;
			case 4:
				return 0;
			default:
				 printf("No NO NO!! stupid. Enter 0 - 4 \n\n");
				 break;
		}
	}
}