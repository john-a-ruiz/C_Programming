/*
 *  ex12_6.c
 *  xch12
 *
 *  rewriting functions using top_ptr
 */

#include <stdio.h>

#define STACK_SIZE 100
#define TRUE 1
#define FALSE 0

typedef int Bool;

int contents[STACK_SIZE];	// external
//int top = 0;				// external
int *top_ptr;			// external

void make_empty(void)
{
	top_ptr = contents;
	//top = 0;
}

Bool is_empty(void)
{
	return top_ptr == contents;
	//return top == 0;
}

Bool is_full(void)
{
	return top_ptr == contents+STACK_SIZE;
	return top == STACK_SIZE;
}

