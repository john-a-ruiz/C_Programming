/*
 * a) define two enums: piece and color. each representing chess parameters
 * b) define a struct: square that can store both pieces and color.
 * c) declare an 8x8 board of type struct square that stores contents of chess board
 * d) initialize board to start of chess game.
 */

#include <stdio.h>

#define ROW 8
#define COL 8

struct square
{
	enum {EMPTY, PAWN, KNIGHT, BISHOP, ROOK, QUEEN, KING} piece;
	enum {BLACK, WHITE} color;
};

int main(void)
{
	struct square board[ROW][COL] =
		   {{{ROOK,WHITE},{KNIGHT,BLACK},{BISHOP,WHITE},{QUEEN,BLACK},{KING,WHITE},{BISHOP,BLACK},{KNIGHT,WHITE},{ROOK,BLACK}},
			{{PAWN,BLACK},{PAWN,WHITE},{PAWN,BLACK},{PAWN,WHITE},{PAWN,BLACK},{PAWN,WHITE},{PAWN,BLACK},{PAWN,WHITE}},
			{{EMPTY,WHITE},{EMPTY,BLACK},{EMPTY,WHITE},{EMPTY,BLACK},{EMPTY,WHITE},{EMPTY,BLACK},{EMPTY,WHITE},{EMPTY,BLACK}},
			{{EMPTY,BLACK},{EMPTY,WHITE},{EMPTY,BLACK},{EMPTY,WHITE},{EMPTY,BLACK},{EMPTY,WHITE},{EMPTY,BLACK},{EMPTY,WHITE}},
			{{EMPTY,WHITE},{EMPTY,BLACK},{EMPTY,WHITE},{EMPTY,BLACK},{EMPTY,WHITE},{EMPTY,BLACK},{EMPTY,WHITE},{EMPTY,BLACK}},
			{{EMPTY,BLACK},{EMPTY,WHITE},{EMPTY,BLACK},{EMPTY,WHITE},{EMPTY,BLACK},{EMPTY,WHITE},{EMPTY,BLACK},{EMPTY,WHITE}},
			{{PAWN,WHITE},{PAWN,BLACK},{PAWN,WHITE},{PAWN,BLACK},{PAWN,WHITE},{PAWN,BLACK},{PAWN,WHITE},{PAWN,BLACK}},
			{{ROOK,BLACK},{KNIGHT,WHITE},{BISHOP,BLACK},{QUEEN, WHITE},{KING,BLACK},{BISHOP,WHITE},{KNIGHT,BLACK},{ROOK,WHITE}}};


			return 0;
}
