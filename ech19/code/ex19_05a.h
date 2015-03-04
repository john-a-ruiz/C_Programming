/*
 * modifying  FIFO is ex1 to define a FIFO type, modify the functions to take a FIFO (FIFO *) parameter
 */

#ifndef 19_05A_H_
#define 19_05A_H_

#define PUBLIC // empty
#define PRIVATE static
#define FIFO_SIZE 10
#define LENGTH 8

typedef struct
{
	int head;
	int tail;
	int FIFO[FIFO_SIZE];
} Fifo;

PUBLIC int insert(Fifo *q);
PUBLIC int delete(Fifo *q);
PUBLIC int first(Fifo *q);
PUBLIC int last(Fifo *q);
PUBLIC int empty(Fifo *q);

struct
{
	char *command;
	int (*function)(Fifo *q);
} command_list[] =
	{
		{"insert",	insert},
		{"delete",	delete},
		{"first",	first},
		{"last",	last},
		{"empty", 	empty}
	};

#endif /* 19_05A_H_ */
