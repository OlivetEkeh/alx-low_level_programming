#include <stdlib.h>

/**
 * free_grid - frees a 2 dimensional grid created by alloc_grid
 * @grid: the 2D grid to be freed
 * @height: height of the grid
 *
 * Return: Nothing.
 */
void free_grid(int **grid, int height)
{
	if (grid == NULL || height <= 0)
		return;

	for (int h = 0; h < height; h++)
	{
	free(grid[h]);
	}
	free(grid);
}
