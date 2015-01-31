/*
 *  ex10_3.c
 *  xch10
 *
 *	classified a poker hand
 */

#include <stdio.h>
#include <stdlib.h>

#define NUM_RANKS 13
#define NUM_SUITS 4
#define NUM_CARDS 5
#define TRUE 1
#define FALSE 0

typedef int Bool;


Bool straight, flush, four, three;
int pairs;	//can be 0, 1, 2

void read_cards(int num_in_rank[], int num_in_suits[]);
void analyze_hand(int num_in_rank[], int num_in_suits[]);
void print_result(void);

int main()
{
	int num_in_rank[NUM_RANKS];
	int num_in_suits[NUM_SUITS];
	
	for (;;)
	{
		read_cards(num_in_rank, num_in_suits);
		analyze_hand(num_in_rank, num_in_suits);
		print_result();
	}
}

void read_cards(int num_in_rank[], int num_in_suits[])
{
	Bool card_exists[NUM_RANKS][NUM_SUITS];
	char ch, rank_ch, suit_ch;
	int rank, suit;
	Bool bad_card;
	int cards_read = 0;
	
	for (rank = 0; rank < NUM_RANKS; rank++)
	{
		num_in_rank[rank] = 0;
		for (suit = 0; suit < NUM_SUITS; suit++)
			card_exists[rank][suit] = FALSE;
	}
	
	for (suit = 0; suit < NUM_SUITS; suit++)
		num_in_suits[suit] = 0;
	
	printf("\n\nEnter 0 to Exit\n\n");
	while (cards_read < NUM_CARDS)
	{
		bad_card = FALSE;
		
		printf("Enter a card: ");
		
		rank_ch = getchar();
		switch (rank_ch)
		{
			case '0':			exit(0);
			case '2':			rank = 0; break;
			case '3':			rank = 1; break;
			case '4':			rank = 2; break;
			case '5':			rank = 3; break;
			case '6':			rank = 4; break;
			case '7':			rank = 5; break;
			case '8':			rank = 6; break;
			case '9':			rank = 7; break;
			case 't': case 'T':	rank = 8; break;
			case 'j': case 'J':	rank = 9; break;
			case 'q': case 'Q':	rank = 10; break;
			case 'k': case 'K':	rank = 11; break;
			case 'a': case 'A':	rank = 12; break;
			default:			bad_card = TRUE;
		}
		
		suit_ch = getchar();
		switch (suit_ch)
		{
			case 'c': case 'C':	suit = 0; break;
			case 'd': case 'D':	suit = 1; break;
			case 'h': case 'H':	suit = 2; break;
			case 's': case 'S':	suit = 3; break;
			default:			bad_card = TRUE;
		}
		
		while ((ch = getchar()) != '\n')
			if (ch != ' ')
				bad_card = TRUE;
		
		if (bad_card)
			printf("Bad card; ignored.\n");
		else if (card_exists[rank][suit])
			printf("Duplicate card; ignored.\n");
		else
		{
			num_in_rank[rank]++;
			num_in_suits[suit]++;
			card_exists[rank][suit] = TRUE;
			cards_read++;
		}
	}
}

void analyze_hand(int num_in_rank[], int num_in_suits[])
{
	int num_consec = 0;
	int rank, suit;
	
	straight = flush = four = three = FALSE;
	pairs = 0;
	
	//check for flush
	for (suit = 0; suit < NUM_SUITS; suit++)
		if (num_in_suits[suit] == NUM_CARDS)
			flush = TRUE;
	
	//check for straight
	rank = 0;
	while (num_in_rank[rank] == 0)
		rank++;
	for ( ;rank < NUM_RANKS && num_in_rank[rank]; rank++)
		num_consec++;
	if (num_consec == NUM_CARDS)
	{
		straight = TRUE;
		return;
	}
	
	//check for 4, 3, 2 of-a-kind
	for (rank = 0; rank < NUM_RANKS; rank++)
	{
		if (num_in_rank[rank] == 4)
			four = TRUE;
		if (num_in_rank[rank] == 3)
			three = TRUE;
		if (num_in_rank[rank] == 2)
			pairs++;
	}
}

void print_result(void)
{
	if (straight && flush)
		printf("Straight Flush\n\n");
	else if (four)
		printf("Four of a Kind\n\n");
	else if (three && pairs == 1)
		printf("Full House\n\n");
	else if (flush)
		printf("Flush\n\n");
	else if (straight)
		printf("Striaght\n\n");
	else if (three)
		printf("Three of a Kind\n\n");
	else if (pairs == 2)
		printf("Two Pairs\n\n");
	else if (pairs == 1)
		printf("Pair\n\n");
	else
		printf("High Card\n\n");
}
