/*
 *  ex10_4.c
 *  xch10
 *
 *	modify poker.c to make one 5x2 array to store cards (I just modified read_cards)
 */

#include <stdio.h>
#include <stdlib.h>

#define ROW 5
#define COL 2
#define NUM_CARDS 5
#define TRUE 1
#define FALSE 0

typedef int Bool;

int hand[ROW][COL] = {0};
Bool straight, flush, four, three;
int pairs;	//can be 0, 1, 2

void read_cards(void);
void analyze_hand(void);
void print_result(void);

int main()
{
	for (;;)
	{
		read_cards();
		analyze_hand();
		print_result();
	}
}

void read_cards(void)
{
	char ch, rank_ch, suit_ch;
	int rank, suit, row, col, i, j;
	Bool bad_card, duplicate_card;
	int cards_read = row = col = i = j = 0;
	
	printf("\n\nEnter 0 to Exit\n\n");
	for (row = 0, col = 0;cards_read < NUM_CARDS; row++)
	{
		bad_card = FALSE;
		duplicate_card = FALSE;
		
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
		
		for (i = 0, j = 0; i < 5; i++)
		{
			if (hand[i][j] == rank && hand[i][j+1] == suit)
				duplicate_card = TRUE;
		}
		
		
		if (bad_card)
			printf("Bad card; ignored.\n");
		else if (duplicate_card)
			printf("Duplicate card; ignored.\n");
		else
		{
			hand[row][col] = rank;
			hand[row][col+1] = suit;
			cards_read++;
		}
	}
}

void analyze_hand(void)
{
	int num_consec = 0;
	int rank, suit, row, col;
	
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