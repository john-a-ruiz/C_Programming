/*
 * RPN Calculator
 */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "stack.h"

#define TOKENS 20
#define POP 	\
		number2 = pop(); \
		number1 = pop();
#define NEXT_TOKEN	\
		p_token = next_token(p_token);

int main(void)
{
	char line[TOKENS+1] = {0};
	int number1 = 0, number2 = 0;
	char *p_token = &line[0];

	while ((!is_full()) && (*p_token != '$'))
	{
		printf("RPN me something ($ to stop): ");
		read_line(line, TOKENS);
		p_token = &line[0];

		while ((*p_token != '\0') && (*p_token != '$'))
		{
			switch (*p_token)
			{
				case '+':
					POP
					push(number1 + number2);
					break;

				case '-':
					POP
					push(number1 - number2);
					break;

				case '*':
					POP
					push(number1 * number2);
					break;

				case '/':
					POP
					push(number1 / number2);
					break;

				default:
					push(atoi(p_token));
					break;
			}
			NEXT_TOKEN
		}
		if (*p_token != '$')
			printf("\n%d\n", answer());
	}

	printf("\nThanks for playing.");
	return 0;
}
