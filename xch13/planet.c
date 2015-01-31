/*
 *  planet.c
 *  xch13
 *
 *	checks planet names using command line arguments
 */

#include <stdio.h>
#include <string.h>

#define NUM_PLANETS 9

int main( int argc, char *argv[])
{
	char *planets[] = {"Mercury", "Venus", "Earth",
					   "Mars", "Jupiter", "Saturn",
					   "Uranus", "Neptune", "Pluto"};
	int i, j;
	i = j = 0;
	
	printf("\n\n");
	for (i = 1; i < argc; i++)
	{
		for (j = 0; j < NUM_PLANETS; j++)
			if (strcmp(argv[i], planets[j]) == 0)
			{
				printf("%s is planet %d\n", argv[i], j+1);
				break;
			}
		
		if (j == NUM_PLANETS)
			printf("%s is not a planet\n", argv[i]);
	}
	
	printf("\n\n");
	return 0;
}

