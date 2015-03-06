/*
 * using bitwise operators write a function that swaps lsb with msb i.e. 0x1234 > 0x3412
 */

#include <stdio.h>

unsigned short int swap_bytes(unsigned short int i);

int main(void)
{
	unsigned short int swapper = 0;
	unsigned short int swapee = 0;

	printf("Gimme a 4 byte hex number (0xNNNN): ");
	scanf("0x%4hX", &swapper);

	swapee = swap_bytes(swapper);

	printf("Tee Hee, I swapped your bits: 0x%.4hX", swapee);

	return 0;
}

unsigned short int swap_bytes(unsigned short int i)
{
	return ((i << 8) | (i >> 8));
}
