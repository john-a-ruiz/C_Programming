/*
 ============================================================================
 Name        : ex14_01.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : write macros that compute
 	 	 	 	 a) the cube of x
 	 	 	 	 b) remainder when x divided by 4
 	 	 	 	 c) 1 if product of x and y is less that 100, 0 otherwise
 ============================================================================
 */

#include <stdio.h>

#define SPACE printf("\n\n");
#define CUBE(x) ((x)*(x)*(x))
#define MODULO(y) ((y)%4)
#define DECIDE(x,y) (((x)*(y)) < 100 ? 1 : 0)

int main(void)
{
	int x = 0;
	int y = 0;

	// A
	printf("Enter a number for me to cube: ");
	scanf("%d", &x);

	printf("%d^3 = %d", x, CUBE(x));

	// B
	SPACE
	printf("Give me a number so I can divide it by 4: ");
	scanf("%d", &y);

	printf("The remainder of %d/4 = %d", y, MODULO(y));

	// C
	SPACE
	printf("The product of %d and %d is %d therefore: %d", x, y, x*y, DECIDE(x,y));

	return 0;
}
