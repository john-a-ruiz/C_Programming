/*
 * allocate space for structure and initialize it
 */

#include <stdio.h>
#include <stdlib.h>

struct point
{
	int x;
	int y;
};

struct rectangle
{
	struct point upper_left;
	struct point lower_right;
};

int main(void)
{
	struct rectangle *p;

	p = malloc(sizeof(struct rectangle));

	p->lower_right.x = 1;
	p->lower_right.y = 0;
	p->upper_left.x = 0;
	p->upper_left.y = 1;

	exit(EXIT_SUCCESS);
}
