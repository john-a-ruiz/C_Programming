/*
 * use shape struct and write functions that perform operations on shape struct s passed as
 * an argument
 * a) compute area of s
 * b) compute center of s, return it as point
 * c) move s by x,y units in x,y direction (x,y passed in function)
 * d) determine if point p lies within s, returning T or F (p is argument - struct point)
 */

#include <stdio.h>
#include <math.h>

#define TRUE 1
#define FALSE 0
#define RECTANGLE 1
#define CIRCLE 0
#define PI 3.14

struct point
{
	float x, y;
};

struct shape
{
	int shape_kind;				// rectangle:1 or circle:0
	struct point center;		// rect: point of lower left corner
	union
	{
		struct
		{
			int length, height;
		} rectangle;
		struct
		{
			int radius;
		} circle;
	} u;
};

struct shape create(struct shape s);
void area(struct shape s);
struct point center(struct shape s);
void move(struct shape s, struct point p);
int within(struct shape s, struct point p);

int main(void)
{
	char code = 0;
	struct point p;
	struct shape s;

	for (;;)
	{
		printf("What would you like to do (c-create, a-area, e-center, m-move, "
				"w-within, q-quit): ");
		scanf(" %c", &code);
		while (getchar() != '\n')
			;

		switch(code)
		{
			case 'c':
				s = create(s);
				break;
			case 'a':
				area(s);
				break;
			case 'e':
				p = center(s);
				printf("The center of your shape is %.2f,%.2f.\n", p.x, center(s).y);
				break;
			case 'm':
				printf("How far do you want to move your shape in the x,y direction: ");
				scanf("%f,%f", &p.x, &p.y);
				move(s, p);
				break;
			case 'w':
				printf("Give me a point x,y and I'll find out if it's within your shape: ");
				scanf("%f,%f", &p.x, &p.y);

				printf("Point %.2f,%.2f is ", p.x, p.y);
				if (within(s, p) == TRUE)
					printf("within your shape.\n");
				else
					printf("not within your shape.\n");
				break;
			case 'q':
				return 0;
			default:
				printf("Illegal Code");
		}
		printf("\n");
	}
}

struct shape create(struct shape s)
{
	char code = 0;

	printf("What shape would you like to make (r-rectangle, c-circle): ");
	scanf(" %c", &code);
	while (getchar() != '\n')
		;

	switch(code)
	{
		case 'r':
			s.shape_kind = RECTANGLE;

			printf("Enter lower left corner x,y: ");
			scanf("%f,%f", &s.center.x, &s.center.y);

			printf("Enter the length,width: ");
			scanf("%d,%d", &s.u.rectangle.length, &s.u.rectangle.height);
			break;
		case 'c':
			s.shape_kind = CIRCLE;

			printf("Enter the center point x,y: ");
			scanf("%f,%f", &s.center.x, &s.center.y);

			printf("Enter the radius: ");
			scanf("%d", &s.u.circle.radius);
			break;
		default:
			printf("Invalid Shape\n");
	}

	return s;
}

void area(struct shape s)
{
	int shape = s.shape_kind;

	switch(shape)
	{
		case RECTANGLE:
			printf("The area of your rectangle is %d.\n",
					s.u.rectangle.length * s.u.rectangle.height);
			break;
		case CIRCLE:
			printf("The area of your circle is %.2f.\n",
					(PI * (s.u.circle.radius * s.u.circle.radius)));
			break;
	}
}

struct point center(struct shape s)
{
	int shape = s.shape_kind;
	struct point c;

	switch(shape)
	{
		case RECTANGLE:
			c.x = s.center.x + (s.u.rectangle.length / 2.0);
			c.y = s.center.y + (s.u.rectangle.height / 2.0);
			break;
		case CIRCLE:
			c.x = s.center.x;
			c.y = s.center.y;
			break;
	}

	return c;
}

void move(struct shape s, struct point p)
{
	int shape = s.shape_kind;

	switch(shape)
	{
		case RECTANGLE:
			printf("Your rectangle's lower left corner moved from %.2f,%.2f to %.2f,%.2f.\n",
					s.center.x, s.center.y, (s.center.x + p.x), (s.center.y + p.y));
			break;
		case CIRCLE:
			printf("Your circle's center moved from %.2f,%.2f to %.2f,%.2f.\n",
					s.center.x, s.center.y, (s.center.x + p.x), (s.center.y + p.y));
			break;
	}
}

int within(struct shape s, struct point p)
{
	int shape = s.shape_kind;
	float a, b, c;
	a = b = c = 0;

	switch(shape)
	{
		case RECTANGLE:
			if ((p.x >= s.center.x) && (p.x <= (s.center.x + s.u.rectangle.length)))
				if ((p.y >= s.center.y) && (p.y <= (s.center.y + s.u.rectangle.height)))
					return TRUE;
			return FALSE;
		case CIRCLE:
			a = p.x - s.center.x;
			b = p.y - s.center.y;
			c = sqrt( pow(a, 2) + pow(b, 2));

			if (c <= s.u.circle.radius)
				return TRUE;
			return FALSE;
	}
}

























