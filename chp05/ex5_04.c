/*
	push out a three banger
*/

#include <stdio.h>

int main()
{
	int i, j, k;
	i = j = k = 0;
	
	printf("\n\nEnter a value for i: ");
	scanf("%d", &i);
	
	printf("Enter a value for j: ");
	scanf("%d", &j);
	
	k = i < j ? -1 : i > j;  //the assignment
	
	printf("The answer is: %d \n\n", k);
	
	return 0;
}