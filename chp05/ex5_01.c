/*
	showing the output of each segment of code
*/

#include <stdio.h>

int main()
{
	int i, j, k;
	i = j = k = 0;
	
//	i = 2, j = 3;
//	k = i * j == 6;
//	printf("\n\n%d \n\n", k);

//	i = 5; j = 10; k = 1;
//	printf("\n\n%d \n\n", k > i < j);

//	i = 3; j = 2; k = 1;
//	printf("\n\n%d \n\n", i < j == j < k);

	i = 3; j = 4; k = 5;
	printf("\n\n%d \n\n", j + i < k);

	return 0;
}