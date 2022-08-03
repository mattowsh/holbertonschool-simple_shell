#include "main.h"

/**
 * error - Creates the message error to be printed when interactive
 * shell mode will fail
 * @b : input entered by the user
 *
 * Return: a string without NULL final byte
 */

char *error(char *b)
{
	int j = 0;
	char *message, prompt[6] = "./hsh";

	while (b[j])
		j++;

	message = malloc(sizeof(char) * (j + 8));
	if (!message)
		return (NULL);

	strcat(message, prompt);
	strcat(message, ": ");
	strcat(message, b);

	return (message);
}
