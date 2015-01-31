/*
	Show how compiler outputs code
*/

#include <stdio.h>

int main()
{
	int i, j, k;
	i = j = k = 0;
	
//	i = 1;
//	printf("\n\n%d ", i++ - 1);
//	printf("%d \n\n", i);

//	i = 10; j = 5;
//	printf("\n\n%d ", i++ - ++j);
//	printf("%d %d \n\n", i, j);

//	i = 7; j = 8;
//	printf("\n\n%d ", i++ - --j);
//	printf("%d %d \n\n", i, j);

	i = 3; j = 4; k = 5;
	printf("\n%d ", i++ - j++ + --k);
	printf("%d %d %d \n\n", i, j, k);
	
	return 0;
}