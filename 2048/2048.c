/*
 *  Name: Bailey Chittle
 *  Date: March 10 2019
 *  Program description: based off of this kattis problem: https://open.kattis.com/problems/2048
 *  mimicks the game 2048 by implementing its algorithm for working with 2D arrays to
 *  move numbers and swap numbers. 
 */

#include <stdio.h>

/*        1 ^
 * 0 <=           2 =>
 * 	  3 \/
 *
 *    0    2    4    8 
 *    16   32   64   128
 *    256  512  1024 2048
 *
 */
void translate(int grid[4][4], int direction);

int main(void)
{
	int grid[4][4];
	int direction;

	// loop to scan for each value in the 4x4 matrix
	for (int r = 0; r < 4; r++) 
	{
		for (int c = 0; c < 4; c++)
		{
			scanf("%d", &grid[r][c]);
		}
	}
	// scan the direction number
	scanf("%d", &direction);	

	// translate function does stuff
	translate(grid, direction);

	// print the new value of the translated matrix
	for (int r = 0; r < 4; r++) 
	{
		for (int c = 0; c < 4; c++) 
		{
			printf("%d ", grid[r][c]);
		}
		printf("\n");
	}

	return 0;
}

/*
 *  translate: function takes a 2d array of size 4x4 and an integer from 0 to 3
 *  and translates by grouping the same values as well as moving numbers across empty
 *  cells (0). Result is similar to the game 2048. 
 *
 *  0, 1, 2, and 3 represent left, up, right and down swipes respectively
 *
 *  ex:
 *  2 0 0 2
 *  4 16 8 2
 *  2 64 32 4
 *  1024 1024 64 0
 *  
 *  if this matrix is swapped left (enter 0) this is the result:
 *
 *  4 0 0 0
 *  4 16 8 2
 *  2 64 32 4
 *  2048 64 0 0
 *
 *  this example shows that numbers group together (2 and 2 make 4 and 1024 and 1024 make 2048)
 *  and they also move to the furthermost left so all zeroes are on the right and the numbers are
 *  on the left with their same order. 
 */
void translate(int grid[4][4], int direction)
{
	/*
	 *  4 cases: a different function for left, up, right, and down swaps. 
	 *  each looks generally the same, but they have different bounds in their loops.
	 *  case 0 and 2 keep the row r as a pivot (not changing) and cycle through each
	 *  row, whereas case 1 and 3 keep column c as a pivot and cycle through each
	 *  column to swap with the respective algorithm
	 */
	switch(direction)
	{
		// left swap
		case 0:
			// cycles through rows and swaps them respectively
			for (int r = 0; r < 4; r++)
			{
				for (int i = 0; i < 3; i++)
				{
					// move numbers (so zeroes on right and numbers on left)
					if (grid[r][i] == 0)
					for (int j = i+1; j < 4; j++)
					{
						if (grid[r][j] != 0)
						{
							grid[r][i] = grid[r][j];
							grid[r][j] = 0;
							break;
						}
					}
					// group numbers together (ex: 2 0 0 2 brings 4 0 0 0, so 2 and 2 grouped together)
					for (int j = i+1; j < 4; j++)
					{
						if (grid[r][i] == grid[r][j])
						{
							grid[r][i] *= 2;
							grid[r][j] = 0;
							break;
						}
						else if (grid[r][j] != 0)
						{
							break;
						}
					}
				}
			}
			break;
		// up swap
		 case 1:
			// cycles through columns and swaps each column. 
			for (int c = 0; c < 4; c++)
			{
				// similar comments to case 0
				for (int i = 0; i < 3; i++)
				{
					if (grid[i][c] == 0)
					for (int j = i+1; j < 4; j++)
					{
						if (grid[j][c] != 0)
						{
							grid[i][c] = grid[j][c];
							grid[j][c] = 0;
							break;
						}
					}
					for (int j = i+1; j < 4; j++)
					{
						if (grid[i][c] == grid[j][c])
						{
							grid[i][c] *= 2;
							grid[j][c] = 0;
							break;
						}
						else if (grid[j][c] != 0)
						{
							break;
						}
					}
				}
			}
			break;
		// right swap
		case 2:
			// similar comments to case 0
			for (int r = 0; r < 4; r++)
			{
				for (int i = 3; i >= 1; i--)
				{
					if (grid[r][i] == 0)
					for (int j = i-1; j >= 0; j--)
					{
						if (grid[r][j] != 0)
						{
							grid[r][i] = grid[r][j];
							grid[r][j] = 0;
							break;
						}
					}
					for (int j = i-1; j >= 0; j--)
					{
						if (grid[r][i] == grid[r][j])
						{
							grid[r][i] *= 2;
							grid[r][j] = 0;
							break;
						}
						else if (grid[r][j] != 0)
						{
							break;
						}
					}
				}
			}
			break;
		// down swap
		case 3:
			// similar comments to case 0 and 1
			for (int c = 0; c < 4; c++)
			{
				for (int i = 3; i >= 1; i--)
				{
					if (grid[i][c] == 0)
					for (int j = i-1; j >= 0; j--)
					{
						if (grid[j][c] != 0)
						{
							grid[i][c] = grid[j][c];
							grid[j][c] = 0;
							break;
						}
					}
					for (int j = i-1; j >= 0; j--)
					{
						if (grid[j][c] == grid[i][c])
						{
							grid[i][c] *= 2;
							grid[j][c] = 0;
							break;
						}
						else if (grid[j][c] != 0)
						{
							break;
						}
					}
				}
			}
			break;

	}
}
