/*
 * declare a tag for a structure
 */

#include <stdio.h>

struct complex
{
	double re;
	double im;
};

struct complex make_complex(double x, double y);
struct complex add_complex(struct complex x, struct complex y);

int main(void)
{
	struct complex c1, c2, c3, c4;

	c1 = make_complex(2.5, 3.3);
	c2 = make_complex(55.6, 43.4);
	c3 = make_complex(12.2, 434.4);

	c4 = add_complex(c1, c2);
	c4 = add_complex(c2, c3);

	return 0;
}

struct complex make_complex(double x, double y)
{
	struct complex vector;

	vector.re = x;
	vector.im = y;

	return vector;
}

struct complex add_complex(struct complex x, struct complex y)
{
	struct complex vector;

	vector.re = x.re + y.re;
	vector.im = x.im +y.im;

	return vector;
}
