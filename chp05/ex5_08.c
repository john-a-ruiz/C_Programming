/*
	user enters wind velocity (knots) and we display correct Beaufort scale reading
*/

#include <stdio.h>

int main()
{
	int velocity = 0;
	
	
	printf("\n\nEnter a wind velocity (knots): ");
	scanf("%d", &velocity);
	
	printf("Old Man Beaufort says: ");
	
	if (velocity < 1)
		printf("Calm \n\n");
	else if (1 <= velocity && velocity <= 3)
		printf("Light Air \n\n");
	else if (4 <= velocity && velocity <= 27)
		printf("Breeze \n\n");
	else if (28 <= velocity && velocity <= 47)
		printf("Gale \n\n");
	else if (48 <= velocity && velocity <= 63)
		printf("Storm \n\n");
	else 
		printf("Hurricane!!! \n\n");
		
	return 0;
}