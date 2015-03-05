/*
 * performs xor encryption
 */

#include <ctype.h>
#include <stdio.h>

#define KEY '&'

int main(void)
{
	int orig_char, new_char;

	printf("Gimme something to encrypt son!!\n");

	while ((orig_char = getchar()) != EOF)
	{
		new_char = orig_char ^ KEY;
		if (iscntrl(orig_char) || iscntrl(new_char))
			putchar(orig_char);
		else
			putchar(new_char);
	}

	return 0;
}
