/*
 *  ex8_11.c
 *  xch08
 *
 *	read a 5x5 array of integers then print the row and column sums
 */

#include <stdio.h>

int main()
{
	int matrix[5][5] = {0};
	int row, col, row_total, col_total;
	row = col = row_total = col_total = 0;
	
	printf("\n\n");
	
	for (row = 0; row < 5; row++)
	{
		printf("Enter row %d: ", row + 1);
		for (col = 0; col < 5; col++)
			scanf("%d", &matrix[row][col]);
	}
	
	printf("\n\nRow Totals: ");
	for (row = 0; row < 5; row++)
	{
		for (col = row_total = 0; col < 5; col++)
			row_total += matrix[row][col];
		printf(" %d", row_total);
	}
	
	printf("\nColumn Totals: ");
	for (col = 0; col < 5; col++)
	{
		for (row = col_total = 0; row < 5; row++)
			col_total += matrix[row][col];
		printf(" %d", col_total);
	}
	
	printf("\n\n");
	return 0;
}

