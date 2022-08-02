#include "main.h"

/**
 * _getenv - Searchs the PATH environment variable on
 * the environment
 * @e : the  environment list
 *
 * Return: the value of PATH in string format
 */

char *_getenv(char **e)
{
	char **env = e, *p, *result;
	int i;

	for (i = 0; env[i]; i++)
	{
		p = strdup(env[i]);
		p = strtok(p, "=");
		if (strcmp(p, "PATH") == 0)
			break;
	}
	p = strtok(NULL, "=");
	result = strdup(p);
	return (result);
}
/*
int main (int ac, char *av, char **env)
{
	char *res = _getenv(env);
	printf("%s\n", res);

	return (0);
}*/
