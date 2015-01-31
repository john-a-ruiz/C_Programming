/*
 *  work with two structs and functions that manipulate them
 */

#include <stdio.h>
#include <ctype.h>
#include <string.h>

#define TRUE 1
#define FALSE 0

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

int area(struct rectangle rect);
struct point center(struct rectangle rect);
struct rectangle move(struct point displace, struct rectangle rect);
int within(struct point p, struct rectangle rect);

int main(void)
{
	struct rectangle bob;
	struct point centerP, displace, pointW;

	printf("Give me one upper-left point on an x-y plane: ");
	scanf("%d,%d", &bob.upper_left.x, &bob.upper_left.y);
	printf("Give me one lower-right point so I can define an area: ");
	scanf("%d,%d", &bob.lower_right.x, &bob.lower_right.y);

	printf("\nThe area of your rectangle is %d.", area(bob));

	centerP = center(bob);
	printf("\nThe center of your rectangle is %d,%d.", centerP.x, centerP.y);

	printf("\nNow I'm going to move your rectangle in the x and y directions,\n"
			"Gimme, how far in each direction: ");
	scanf("%d,%d", &displace.x, &displace.y);
	printf("\nYour old rectangle coordinates were: (%d,%d) (%d,%d)",
			bob.upper_left.x, bob.upper_left.y, bob.lower_right.x, bob.lower_right.y);
	bob = move(displace, bob);
	printf("\nYour newly moved rectangle has coordinates: (%d,%d) (%d,%d)",
			bob.upper_left.x, bob.upper_left.y, bob.lower_right.x, bob.lower_right.y);

	printf("\nGimme a point and I'll find out if it's within your rectangle: ");
	scanf("%d,%d", &pointW.x, &pointW.y);
	printf("\nThe point %s lie within your rectangle.", within(pointW, bob) > 0 ? "Does" : "Doesn't");

	return 0;
}

int area(struct rectangle rect)
{
	int area, length, height;
	area = length = height = 0;

	height = rect.upper_left.y - rect.lower_right.y;
	length = rect.lower_right.x - rect.upper_left.x;
	area = length * height;

	return area;
}

struct point center(struct rectangle rect)
{
	struct point center;

	int length, height, centerX, centerY;
	length = height = centerX = centerY = 0;

	height = rect.upper_left.y - rect.lower_right.y;
	length = rect.lower_right.x - rect.upper_left.x;

	center.x = length / 2;
	center.y = height / 2;

	return center;
}

struct rectangle move(struct point displace, struct rectangle rect)
{
	rect.upper_left.x += displace.x;
	rect.lower_right.x += displace.x;

	rect.upper_left.y += displace.y;
	rect.lower_right.y += displace.y;

	return rect;
}

int within(struct point p, struct rectangle rect)
{
	if ((p.x >= rect.upper_left.x) && (p.x <= rect.lower_right.x))
		if ((p.y >= rect.lower_right.y) && (p.y <= rect.upper_left.y))
			return TRUE;

	return FALSE;
}
