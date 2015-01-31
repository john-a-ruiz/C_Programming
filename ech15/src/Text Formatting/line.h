/*
 * line.h
 *
 *  Created on: Nov 16, 2014
 *      Author: johnruiz
 */

#ifndef LINE_H_
#define LINE_H_

/*
 * clear_line: clears the current line.
 */
void clear_line(void);

/*
 ============================================================================
 Name        : add_word
 Description : adds word to the end of the current line. If this is not the
 	 	 	   first word on the line, puts one space before word.
 ============================================================================
 */
void add_word(const char *word);

/*
 ============================================================================
 Name        : space_remaining
 Description : returns the number of character left in the current line.
 ============================================================================
 */
int space_remaining(void);

/*
 ============================================================================
 Name        : write_line
 Description : writes the current line with justification.
 ============================================================================
 */
void write_line(void);

/*
 ============================================================================
 Name        : flush_line
 Description : writes the current line withou justification. If the line is
 	 	 	   empty, does nothing.
 ============================================================================
 */
void flush_line(void);

#endif /* LINE_H_ */
