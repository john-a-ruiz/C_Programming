/*
	show the output produced by each code fragment
*/

#include <stdio.h>

int main()
{
	int i, j, k;
	i = j = k = 0;
	
//	i = 10; j = 5;
//	printf("\n\n%d \n\n", !i < j);

//	i = 2; j = 1;
//	printf("\n\n%d \n\n", !!i + !j);

//	i = 5; j = 0; k = -5;
//	printf("\n\n%d \n\n", i && j || k);

	i = 1; j = 2; k = 3;
	printf("\n\n%d \n\n", i < j || k);
	
	return 0;
}