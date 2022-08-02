#include "main.h"

/**
 * _getenv - 
 * @env : 
 *
 * Return:
 */

char *_getenv(char **e)
{
	char **env = e;
	char *p, *result;
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
