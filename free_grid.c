#include "main.h"

/**
 * free_grid - Frees a 2 dimensional grid previously created by
 * my alloc_grid function
 * @grid : the address of the two dimensional grid
 * @height : height of the grid
 */

void free_grid(char **grid)
{
	int i = 0, j = 0;

	if (!grid)
		return;
	while (grid[i])
		i++;

	for (; j < i; j++)
		free(grid[j]);

	free(grid);
}

/*int main(void)
{
	char *str = "hola como estas";
	char **argv;

	argv = set_strtok(str);
	free_grid(argv);
}*/
