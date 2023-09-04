#include "main.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * alloc_grid - returns a pointer to a 2D array of integers
 * @width: width of the grid
 * @height: height of the grid
 *
 * Return: A pointer to a 2D array of integers, or NULL on failure.
 */

int **alloc_grid(int width, int height)
{
	if (width <= 0 || height <= 0)
		return (NULL);

	int **grid = malloc(height * sizeof(int *));

	if (grid == NULL)
	return (NULL);

	for (int h = 0; h < height; h++)
	{
	grid[h] = malloc(width * sizeof(int));
	if (grid[h] == NULL)
	{
		for (int i = 0; i < h; i++){
			free(grid[i]);
			free(grid);}
		return (NULL);
	}

	for (int w = 0; w < width; w++)
		grid[h][w] = 0;
	}

	return (grid);
}

/**
 * main - check the code for ALX School students.
 *
 * Return: Always 0.
 */
int main(void)
{
	int **grid;

	grid = alloc_grid(6, 4);
	if (grid == NULL)
	{
		return (1);
	}
	print_grid(grid, 6, 4);
	printf("\n");
	grid[0][3] = 98;
	grid[3][4] = 402;
	print_grid(grid, 6, 4);

	for (int h = 0; h < 4; h++)
	free(grid[h]);
	free(grid);

	return (0);
}
