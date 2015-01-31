/*
	show the output produced by the code (short-circuit behavior)
*/

#include <stdio.h>

int main()
{
	int i, j, k;
	i = j = k = 0;
	
//	i = 3, j = 4, k = 5;
//	printf("\n\n%d \n\n", i < j || ++j < k);
//	printf("%d %d %d \n\n", i, j, k);

//	i = 7; j = 8; k = 9;
//	printf("\n\n%d \n\n", i - 7 && j++ < k);
//	printf("%d %d %d \n\n", i, j, k);

//	i = 7; j = 8; k = 9;
//	printf("\n\n%d \n\n", (i = j) || (j = k));
//	printf("%d %d %d \n\n", i, j, k);

	i = j = k = 1;
	printf("\n\n%d \n\n", ++i || ++j && ++k);
	printf("%d %d %d \n\n", i, j, k);
			
	return 0;
}