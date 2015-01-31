/*
 *  ex10_2.c
 *  xch10
 *
 *	make a stack that stores chars and checks parenthesis/braces
 *	( = 40		{ = 123
 *	) = 41		} = 125
 */

#include <stdio.h>
#include <stdlib.h>

#define STACK_SIZE 100
#define TRUE 1
#define FALSE 0

typedef int Bool;

char contents[STACK_SIZE] = {0};  //external
int top = 0;					 //external

void make_empty(void);
Bool is_empty(void);
Bool is_full(void);
void push(char i);
char pop(void);
void stack_overflow(void);
void stack_underflow(void);

int main()
{	
	char symbol = '0';
	
	printf("\n\nEnter parentheses and/or braces: ");
	
	do 
	{
		symbol = getchar();
		
		switch (symbol)
		{
			case '{': case '(':
				push(symbol);
				break;
			case ')':
				if (pop() == '(')
					break;
				else 
					printf("Not correct, need bracket!");
				exit(0);
			case '}':
				if (pop() == '{')
					break;
				else
					printf("Not correct, need parenthesis!");
				exit(0);
			case '\n':
				break;
			default:
				printf("Not Specified Input!");
				exit(0);
		}
	} while (symbol != '\n');
	
	printf("\nAll Brackets and Parenthesis match up.\n\n");
	return 0;
}

void make_empty(void)
{
	top = 0;
}

Bool is_empty(void)
{
	return top == 0;
}

Bool is_full(void)
{
	return top == STACK_SIZE;
}

void push(char i)
{
	if (is_full())
		stack_overflow();
	else
		contents[top++] = i;
}

char pop(void)
{
	if (is_empty())
		stack_underflow();
	
	return contents[--top];
}

void stack_overflow(void)
{
	printf("\n\nStack Overflow\n\n");
	exit(0);
}

void stack_underflow(void)
{
	printf("\n\nStack Underflow");
	exit(0);
}