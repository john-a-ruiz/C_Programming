/*
 *  ex13_4.c
 *  xch13
 *
 *	impliment variations to basic read_line function
 *	a) skip white space before storing
 *	b) stop reading at first white space character (isspace fcn)
 *	c) stop reading at first new line char and store it
 *	d) leave behind char it doesn't have room to store
 */

/*
int read_line(char str[], int n)
{
	char ch;
	int i = 0;
	
	while ((ch = getchar()) != '\n')
		if (i < n)
			str[i++] = ch;
		   
	str[i] = '\0';		//terminate string
	return i;			//return length of string
}
*/

#include <stdio.h>

#define STRING 20

int read_line(char str[], int n);

int main()
{
	char str[STRING+1] = {'\0'};
	int length = 0;
	
	printf("\n\ntype me something FOOO!: ");
	length = read_line(str, STRING);
	
	return 0;
}

/* A
int read_line(char str[], int n)
{
	char ch;
	int i = 0;
	
	while ((ch = getchar()) == ' ');
	str[i++] = ch;
	
	while ((ch = getchar()) != '\n')
		if (i < n)
			str[i++] = ch;
	
	str[i] = '\0';		
	return i;		
}
*/

/*B
int read_line(char str[], int n)
{
	char ch;
	int i = 0;
	
	while ((ch = getchar()) == ' ');
	str[i++] = ch;
	
	while ((ch = getchar()) != '\n')
		if (i < n)
			if (isspace(ch))
				break;
			else
				str[i++] = ch;
	
	
	str[i] = '\0';		//terminate string
	return i;			//return length of string
}
*/

/*C
int read_line(char str[], int n)
{
	char ch;
	int i = 0;
	
	while ((ch = getchar()) == ' ');
	str[i++] = ch;
	
	while ((ch = getchar()) != '\n')
		if (i < n)
			str[i++] = ch;
	if (ch == '\n')
		str[i++] = '\n';
	
	str[i] = '\0';		//terminate string
	return i;			//return length of string
}
*/
 
/*D*/
int read_line(char str[], int n)
{
	char ch;
	int i = 0;
	
	while ((ch = getchar()) == ' ');
	str[i++] = ch;
	
	while ((ch = getchar()) != '\n')
		if (i < n)
			str[i++] = ch;
		else
			break;
	
	if (ch == '\n')
		str[i++] = '\n';
	
	str[i] = '\0';		//terminate string
	return i;			//return length of string
}


















