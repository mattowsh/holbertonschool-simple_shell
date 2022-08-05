#include "main.h"

/**
 * _which - Checks if the input is a path. If not, tokenizes PATH
 * variable and generate differentes paths
 * @p : PATH variable tokenized
 * @baux : arguments in string format
 *
 * Return: tokenized paths contemplating the input
 */

char *_which(char *p, char **baux)
{
	char *token = NULL, *p1 = NULL, *full_path = NULL;

	if (strchr(baux[0], '/') && !exists(baux[0]))
		return (strdup(baux[0]));
	if (!p || (strcmp(p, "") == 0))
		return (0);
	p1 = strdup(p);
	token = strtok(p1, ":");
	while (token)
	{
		full_path = malloc(1024);
		strcpy(full_path, token);
		strcat(full_path, "/");
		strcat(full_path, baux[0]);
		if (exists(full_path) == 0)
		{
			free(p1);
			return (full_path);
		}
		free(full_path);
		token = NULL;
		token = strtok(NULL, ":");
	}
	free(p1);
	return (0);
}
