/*
 *  ex12_12.c
 *  xch12
 *
 *	initialize an identity matrix array using a single pointer 
 */

#include <stdio.h>

#define X 5
#define Y 5
#define SPACER 5

int main()
{
	int matrix[Y][X] = {0};
	int *p_element;
	int spacer = 0;
	
	for (p_element = &matrix[0][0]; p_element <= &matrix[Y-1][X-1]; p_element++)
	{
		for (spacer = 0; spacer < SPACER; spacer++, p_element++)
			if (spacer == 0)
				*p_element = 1;
	}
	
	return 0;	
}

