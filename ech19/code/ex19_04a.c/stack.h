/*
 * Using a Stack 'type' we can have as many stacks as we want but we sacrifice information hiding
 * so the user can now much up our shizat.
 * this is a Stack interface.
 */

#ifndef STACK_H_
#define STACK_H_

#define PUBLIC 	// empty
#define PRIVATE static
#define STACK_SIZE 100

PUBLIC typedef struct
{
	int contents[STACK_SIZE];
	int top;
} Stack;

PUBLIC void make_empty(Stack *s);
PUBLIC int is_empty(const Stack *s);
PUBLIC void  push(Stack *s, int i);
PUBLIC int pop(Stack *s);

#endif /* STACK_H_ */
