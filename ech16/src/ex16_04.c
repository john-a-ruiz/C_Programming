/*
 * declare a typedef for a structure
 */

#include <stdio.h>

typedef struct
{
	double re;
	double im;
} complex;

complex make_complex(double re, double im);
complex add_complex(complex x, complex y);

int main(void)
{
	complex c1 = {0}, c2 = {0}, c3 = {0}, c4 = {0};

	c1 = make_complex(5.5, 4.5);
	c2 = make_complex(1, 5);
	c3 = make_complex(54.5, 12.0);

	c4 = add_complex(c1, c3);

	return 0;
}

complex make_complex(double re, double im)
{
	complex vector;

	vector.re = re;
	vector.im = im;

	return vector;
}

complex add_complex(complex x, complex y)
{
	complex vector;

	vector.re = x.re + y.re;
	vector.im = x.im + y.im;

	return vector;
}
