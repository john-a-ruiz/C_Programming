/*
 * write macros that when given a color as an argument return its 8 bit rgb intensities.
 */

#include <stdio.h>

#define GET_RED(color) (((color) >> 16) & (0x0000FF))
#define GET_GREEN(color) (((color) >> 8) & (0x0000FF))
#define GET_BLUE(color) ((color) & 0x0000FF)

int main(void)
{
	int color = 0;
	int red, green, blue;
	red = green = blue = 0;

	printf("Gimme a 24bit hex color (0x02040A - 0xred,green,blue): ");
	scanf("0x%6X", &color);

	red = GET_RED(color);
	green = GET_GREEN(color);
	blue = GET_BLUE(color);

	printf("The red component is 0x%.2X\n", red);
	printf("The green component is 0x%.2X\n", green);
	printf("The blue component is 0x%.2X\n", blue);

	return 0;
}
