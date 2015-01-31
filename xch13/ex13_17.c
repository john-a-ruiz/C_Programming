/*
 *  ex13_17.c
 *  xch13
 *
 *	modify deal.c to print full name of cards
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define NUM_SUITS 4
#define NUM_RANKS 13
#define TRUE 1
#define FALSE 0

typedef int Bool;

/* original
int main()
{
	Bool in_hand[NUM_SUITS][NUM_RANKS] = {0};
	const char rank_code[] = {'2','3','4','5','6','7','8','9',
		't','j','q','k','a'};
	const char suit_code[] = {'c','d','h','s'};
	int num_cards, rank, suit;
	num_cards = rank = suit = 0;
	
	srand((unsigned) time(NULL));
	
	printf("\n\nEnter number of cards in hand: ");
	scanf("%d",&num_cards);
	
	printf("Your hand:");
	while (num_cards > 0)
	{
		suit = rand() %NUM_SUITS;	//picks a random suit
		rank = rand() %NUM_RANKS;	//picks a random rank
		
		if (!in_hand[suit][rank])
		{
			in_hand[suit][rank] = TRUE;
			num_cards--;
			printf(" %c%c", rank_code[rank], suit_code[suit]);
		}
	}
	printf("\n\n");
	return 0;
}
*/

//modified
int main()
{
	Bool in_hand[NUM_SUITS][NUM_RANKS] = {0};
	const char *rank_code[] = {"two","three","four","five","six","seven",
		"eight","nine","ten","jack","queen","king","ace"};
	const char *suit_code[] = {"clubs","diamonds","hearts","spades"};
	int num_cards, rank, suit;
	num_cards = rank = suit = 0;
	
	srand((unsigned) time(NULL));
	
	printf("\n\nEnter number of cards in hand: ");
	scanf("%d",&num_cards);
	
	printf("Your hand:\n");
	while (num_cards > 0)
	{
		suit = rand() %NUM_SUITS;	//picks a random suit
		rank = rand() %NUM_RANKS;	//picks a random rank
		
		if (!in_hand[suit][rank])
		{
			in_hand[suit][rank] = TRUE;
			num_cards--;
			printf("%s of %s\n", rank_code[rank], suit_code[suit]);
		}
	}
	printf("\n\n");
	return 0;	
}