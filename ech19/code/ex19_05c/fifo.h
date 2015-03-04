/*
 * fifo.h
 *
 *  Created on: Mar 3, 2015
 *      Author: johnruiz
 */

#ifndef FIFO_H_
#define FIFO_H_

#define PUBLIC // empty
#define PRIVATE static
#define FIFO_SIZE 10

PUBLIC struct Fifo
{
	int data;
	struct Fifo *next;
};

PUBLIC int insert(struct Fifo **q);
PUBLIC int delete(struct Fifo **q);
PUBLIC int first(struct Fifo **q);
PUBLIC int last(struct Fifo **q);
PUBLIC int empty(struct Fifo **q);
PUBLIC void readline(char array[], int size);
PUBLIC void execute_command(char array[], struct Fifo **q);

#endif /* FIFO_H_ */
