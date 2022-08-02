#include "main.h"

/**
 * _strcat - concatenate
 * @dest: string
 * @src: string
 * Return: dest
 */

char *_strcat(char *dest, char *src)
{
	int destTotalChars = strlen(dest);
	int totalChars = destTotalChars + (strlen(src));
	int i;
	int j = 0;

	for (i = destTotalChars; i < totalChars; i++)
	{
		dest[i] = src[j];
		j++;
	}
	return (dest);
}
