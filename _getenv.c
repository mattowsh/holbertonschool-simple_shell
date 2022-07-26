#include "main.h"

/**
 * _getenv - Searchs the PATH environment variable on
 * the environment
 * @env : the  environment list
 *
 * Return: the value of PATH in string format
 */

char *_getenv(char *env)
{
	char *p = NULL, *token = NULL, *token_aux = NULL;
	int i;

	if (!environ)
	{
		return (0);
	}
	for (i = 0; environ[i]; i++)
	{
		p = strdup(environ[i]);
		token = strtok(p, "=");
		if (strcmp(token, env) == 0)
		{
			token = strtok(NULL, "=");
			if (token)
			{
				token_aux = strdup(token);
				free(p);
				return (token_aux);
			}
			free(p);
			return (0);
		}
		free(p);
	}

	return (0);
}
