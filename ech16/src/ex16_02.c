/*
 * a) declare struct
 */

#include <stdio.h>

struct
{
	double re;
	double im;
} c1 = {0.0, 1.0},
  c2 = {1.0, 0.0},
  c3;

int main(void)
{
//	c1 = c2;
	c3.re = c1.re + c2.re;
	c3.im = c1.im + c2.im;

	return 0;
}
