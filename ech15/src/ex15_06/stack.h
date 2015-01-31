/*
 * prototypes or declarations of functions which are defined in stack.c
 */

#ifndef STACK_H_
#define STACK_H_

void make_empty(void);
int is_empty(void);
int is_full(void);
void push(int i);
int pop(void);
int answer(void);
void read_line(char array[], int size);
char *next_token(char *element);

#endif /* STACK_H_ */
