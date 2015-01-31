/*
 *  ex13_20.c
 *  xch13
 *
 *	improve planet.c by ignoring the case of the arguments
 */

/* original
 
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
*/

#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define NUM_PLANETS 9

void two_lower(char *src_str1, char *des_str1, char *src_str2, char *des_str2);

int main(int argc, char *argv[])
{
	char *planets[] = {"Mercury", "Venus", "Earth",
		"Mars", "Jupiter", "Saturn",
		"Uranus", "Neptune", "Pluto"};
	char argument[7] = {0}, planet[7] = {0};
	int i, j;
	i = j = 0;
	
	printf("\n\n");
	for (i = 1; i < argc; i++)
	{
		for (j = 0; j < NUM_PLANETS; j++)
		{
			two_lower(argv[i], argument, planets[j], planet);
			
			if (strcmp(argument, planet) == 0)
			{
				printf("%s is planet %d\n", argv[i], j+1);
				break;
			}
		}
		
		if (j == NUM_PLANETS)
			printf("%s is not a planet\n", argv[i]);
	}
	
	printf("\n\n");
	return 0;
}

void two_lower(char *src_str1, char *des_str1, char *src_str2, char *des_str2)
{	
	strncpy(des_str1, src_str1, 7);
	strncpy(des_str2, src_str2, 7);
	
	while (*des_str1)
		*des_str1++ = tolower(*des_str1);
	
	while (*des_str2)
		*des_str2++ = tolower(*des_str2);
}


















