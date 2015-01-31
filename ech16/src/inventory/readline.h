/*
 * read_line:	Skips leading white_space characters, then reads the remainder of the input line
 *				and stores it in str. Truncates the line if its length exceeds n. Returns the
 *				number of characters stored.
 */

#ifndef READLINE_H_
#define READLINE_H_

int read_line(char str[], int n);

#endif /* READLINE_H_ */
