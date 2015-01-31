/*
	Show how compiler outputs code
*/

#include <stdio.h>

int main()
{
	int i, j, k;
	
//	i = 5; j = 3;
//	printf("\n\n%d %d\n\n", i / j, i % j);

//	i = 2; j = 3;
//	printf("\n\n%d\n\n", (i + 10) % j);
	
//	i = 7; j = 8; k = 9;
//	printf("\n\n%d\n\n", (i + 10) % k / j);
	
	i = 1; j = 2; k = 3;
	printf("\n\n%d\n\n", (i + 5) % (j + 2) / k);
		
	return 0;
}