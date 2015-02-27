/*
 * Using a Stack 'type' we can have as many stacks as we want but we sacrifice information hiding
 * so the user can now muck up our shizat.
 * this is a Stack interface using linked list.
 */

#ifndef STACK_H_
#define STACK_H_

#define PUBLIC 	// empty
#define PRIVATE static

PUBLIC struct stack
{
	int data;
	struct stack *next;
};

PUBLIC void make_empty(struct stack **s);
PUBLIC int is_empty(const struct stack *s);
PUBLIC void push(struct stack **s, int i);
PUBLIC int pop(struct stack **s);

#endif /* STACK_H_ */
