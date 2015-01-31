/*
 *  ex12_5a.c
 *  xch12
 *
 *  read message and see if its a palandrome
 */

#include <stdio.h>

#define LETTERS 40

int main()
{
	char message[LETTERS] = {'0'};
	int i, head, tail;
	i = head = tail = 0;
	
	printf("\n\nEnter a message (<20 char): ");
	
	i = 0;
	do message[i++] = getchar();
	while ((i < LETTERS) && (message[i-1] != '\n'));
	
	// check to see if palindrome
	for (head = 0, tail = i-2; head <= tail; head++, tail--)
	{
		if ((message[head] < 65) || (message[head] > 122)) //checks only letters
		{
			tail++;
			continue;
		}
		
		if((message[tail] < 65) || (message[tail] > 122)) //checks only letters
		{
			head--;
			continue;
		}
			
		if (message[head] == message[tail])
			continue;
		else
		{
			printf("Not a Palindrome!\n\n");
			return 0;
		}
	}
	
	printf("Palindrome\n\n");
	return 0;
}

