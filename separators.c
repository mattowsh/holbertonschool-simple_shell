#include "main.h"

/**
 * separators - Checks if a char is a separator like:
 * space, newline, tab or NULL character at the end of the string
 *
 * Return: 1 on success, 0 on error
 */

int separators(char letter)
{
	int i = 0;

	separators_t data[] = {
		{" "},
		{"\n"},
		{"\t"},
		{NULL}
	};

	while (data[i].sep && letter)
	{
		if (data[i].sep[0] == letter)
			return (1);
		i++;
	}

	if (letter == '\0')
		return (1);

	return (0);
}
