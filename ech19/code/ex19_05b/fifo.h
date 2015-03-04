/*
 * fifo.h
 *
 *  Created on: Feb 26, 2015
 *      Author: johnruiz
 */

#ifndef FIFO_H_
#define FIFO_H_

#define PUBLIC // empty
#define PRIVATE static
#define FIFO_SIZE 10

PUBLIC typedef struct
{
	int head;
	int tail;
	int FIFO[FIFO_SIZE];
} Fifo;

PUBLIC int insert(Fifo **q);
PUBLIC int delete(Fifo **q);
PUBLIC int first(Fifo **q);
PUBLIC int last(Fifo **q);
PUBLIC int empty(Fifo **q);
PUBLIC int clear(Fifo **q);
PUBLIC void readline(char array[], int size);
PUBLIC void execute_command(char array[], Fifo **q);

#endif /* FIFO_H_ */
