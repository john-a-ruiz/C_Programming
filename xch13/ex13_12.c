/*
 *  ex13_12.c
 *  xch13
 *
 *	rewrite strcmp using pointer arithmetic
 */

#include <stdio.h>

int strcmp(char *s, char *t);
int p_strcmp(char *s, char *t);

int main()
{
	int x, y;
	x = y = 0;
	
	char *s = "s";
	char *t = "cs";
	
	x = strcmp(s, t);
	y = p_strcmp(s, t);
	
	return 0;
}

int strcmp(char *s, char *t)
{
	int i;
	
	for (i = 0; s[i] == t[i]; i++)
		if (s[i] == '\0')
			return 0;
	return s[i] - t[i];
}

int p_strcmp(char *s, char *t)
{
	for ( ; *s == *t; s++, t++)
		if (*s == '\0')
			return 0;
	return *s - *t;
}