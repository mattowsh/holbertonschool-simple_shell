#include "main.h"

/**
 * main_aux_1 - another auxiliar for main
 * @baux: pointer to strings
 * Return: int
 */

int main_aux_1(char **baux)
{
	if (!baux[0])
	{
		free_grid(baux);
		return (1);
	}
	return (0);
}
