/*
 *  ex8_13.c
 *  xch08
 *
 *	generate a 'random walk' across a 10x10 array
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef int Bool;

int main()
{
	char array[10][10] = {{'.','.','.','.','.','.','.','.','.','.'},
						  {'.','.','.','.','.','.','.','.','.','.'},
						  {'.','.','.','.','.','.','.','.','.','.'},
						  {'.','.','.','.','.','.','.','.','.','.'},
						  {'.','.','.','.','.','.','.','.','.','.'},
						  {'.','.','.','.','.','.','.','.','.','.'},
						  {'.','.','.','.','.','.','.','.','.','.'},
						  {'.','.','.','.','.','.','.','.','.','.'},
						  {'.','.','.','.','.','.','.','.','.','.'},
						  {'.','.','.','.','.','.','.','.','.','.'}};

	
	char path = 'A';
	int direction = 0; //0=up 1=down 2=left 3=right
	int row, col;
	Bool up, down, left, right;
	row = col = 0;
	up = down = left = right = 1;
	
	srand((unsigned) time(NULL));
	
	array[row][col] = path++;
	while ((up == 1 || down == 1 || left == 1 || right == 1) && (path <= 'Z'))
	{
		direction = rand() %4;
		
		switch (direction)
		{
			case 0: //up
				if (row == 0 || array[row-1][col] != '.')
				{
					up = 0;
					break;
				}
				array[--row][col] = path++; 
				up = 1; break;
			case 1: //down
				if (row == 9 || array[row+1][col] != '.')
				{
					down = 0;
					break;
				}
				array[++row][col] = path++; 
				down = 1; break;
			case 2: //left
				if (col == 0 || array[row][col-1] != '.')
				{
					left = 0;
					break;
				}
				array[row][--col] = path++; 
				left = 1; break;
			case 3: //right
				if (col == 9 || array[row][col+1] != '.')
				{
					right = 0;
					break;
				}
				array[row][++col] = path++; 
				right = 1; break;
			default:
				printf("\n\nWTF!\n\n");
				return 0;
		}
	}
	
	printf("\n\n");
	for (row = 0; row < 10; row++)
	{
		for (col = 0; col < 10; col++)
		{
			printf("%c ", array[row][col]);
		}
		printf("\n");
	}
	printf("\n\n");
	
	if (up == 0 && down == 0 && left == 0 && right == 0)
		printf("Fuck!\n\n");
	
	return 0;
}





