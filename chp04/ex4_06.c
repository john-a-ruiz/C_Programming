/*
	Show how compiler outputs code
*/

#include <stdio.h>

int main()
{
	int i, j, k;
	i = j = k = 0;
	
//	i = 7; j = 8;
//	i *= j + 1;
//	printf("\n\n%d %d \n\n", i, j);

//	i = j = k = 1;
//	i += j += k;
//	printf("\n\n%d %d %d \n\n", i, j, k);

//	i = 1; j = 2; k = 3;
//	i -= j -= k;
//	printf("\n\n%d %d %d \n\n", i, j, k);

	i = 2, j = 1, k = 0;
	i *= j *= k;
	printf("\n\n%d %d %d \n\n", i, j, k);
	
	return 0;
}