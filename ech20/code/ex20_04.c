/*
 * write a macro named MK_COLOR with three parameters (red, green, blue) each 8 bits. It should return a long int in
 * which the last three bytes contain red, green, blue intensities
 */

#include <stdio.h>

#define MK_COLOR(red,green,blue) ((red) << 16 | (green) << 8 | (blue))

int main(void)
{
	unsigned int color = 0;
	int red, green, blue;
	red = green = blue = 0;

	printf("Gimme a red value: ");
	scanf("%d", &red);

	printf("Gimme a green value: ");
	scanf("%d", &green);

	printf("Gimme a blue value: ");
	scanf("%d", &blue);

	color = MK_COLOR(red, green, blue);

	printf("Your hex color combo is: 0x%.6X", color);

	return 0;
}


