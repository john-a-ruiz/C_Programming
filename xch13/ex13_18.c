/*
 *  ex13_18.c
 *  xch13
 *
 *	echoes command-line arguments in reverse
 */

#include <stdio.h>
#include <string.h>

#define NUM_WORDS 10

int main(int argc, char *argv[])
{
	int i = 0;
	
	printf("\n\nYour arguments in reverse order:\n");
	for (i = argc-1; i > 0; i--)
		printf("%s ", argv[i]);
	
	printf("\n\n");
	return 0;
}

