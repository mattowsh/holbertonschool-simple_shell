#include "main.h"

/**
 * _getenv - 
 * @env : 
 *
 * Return:
 */

char *_getenv(char **env)
{
	char *p;

	while (env)
	{
		p = strdup(*env);
		printf("ENV: %s\n", p);
		p = strtok(p, "=");
		if (strcmp(p, "PATH"))
		{
			printf("PATH ENCONTRADO: %s\n", p);
			break;
		}
	}

	p = strtok(NULL, "=");
	printf("PATH NULL: %s\n", p);
	return (p);
}

int main (char **env)
{
	_getenv(env);
	printf("SUCCESS\n");

	return (0);
}
