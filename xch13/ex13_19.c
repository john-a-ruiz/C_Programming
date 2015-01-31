/*
 *  ex13_19.c
 *  xch13
 *
 *	add up command-line arguments (integers)
 */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
	int i, sum;
	i = sum = 0;
	
	for (i = 1; i < argc; i++)
		sum += atoi(argv[i]);
	
	printf("\n\nThe sum of your arguments is: %d\n\n", sum);
	
	return 0;
}


