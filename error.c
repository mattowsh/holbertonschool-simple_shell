#include "main.h"

/**
 * error - Creates the message error to be printed when interactive
 * shell mode will fail
 * @av : list of arguments
 * @b : input entered by the user
 *
 * Return: a string without NULL final byte
 */

char *error(char **av, char *b)
{
	int i = 0, j = 0;
	char *message;

	while (av[0][i])
		i++;

	while (b[j])
		j++;

	message = malloc(sizeof(char) * (i + j + 2));
	if (!message)
		return (NULL);

	strcat(message, av[0]);
	strcat(message, ": ");
	strcat(message, b);

	return (message);
}
