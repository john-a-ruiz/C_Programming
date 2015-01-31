/*
 * write a macro that expands into a call of printf that displays the value of the function
 * f when called with argument x
 */

#include <stdio.h>
#include <math.h>

//#define DISP(f,x) (printf("sqrt(%g) = %g\n", 3.0, sqrt(3.0)));
  #define DISP(f,x) (printf(#f"(%g) = %g\n", (x), (f)((x))));
#define DISP2(f,x,y) (printf(#f"(%g,%g) = %g\n", (x), (y), (f)((x),(y))));

int main(void)
{
	DISP(sqrt, 3.0)

	printf("\n\n");

	DISP(exp, 5.0)

	printf("\n\n");

	DISP2(pow, 3.0, 2.0)

	printf("\n\n");

	DISP2(fmod, 5.5, 2.2)

	return 0;
}
