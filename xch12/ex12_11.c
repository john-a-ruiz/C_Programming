/*
 *  ex12_11.c
 *  xch12
 *
 *	write program to practice pointer arith
 */

#include <stdio.h>

#define NUMBERS 5
#define TRUE 1
#define FALSE 0

typedef int Bool;

Bool search(int a[], int n, int key);

int main()
{
	int list[NUMBERS] = {0};
	int key, result, *p_num;
	key = result = 0;
	
	printf("Enter %d numbers to have in list: ", NUMBERS);
	for (p_num = list; p_num < list+NUMBERS; p_num++)
		scanf("%d", p_num); 

	printf("Enter a key to look for: ");
	scanf("%d", &key);
	
	result = search(list, NUMBERS, key);
	
	if (result == TRUE)
		printf("\nYour key was found!\n\n");
	else 
		printf("\nYour key was not found!\n\n");
	
	return 0;
}

Bool search(int a[], int n, int key)
{
	int *p_num;
	
	for (p_num = a; p_num < a+n; p_num++)
	{
		if (*p_num == key)
			return TRUE;
	}
	
	return FALSE;
}
