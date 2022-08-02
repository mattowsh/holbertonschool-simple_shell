#include "main.h"

/**
 * main - Coordinates the execution of programs, creating
 * a child process if is necessary
 * @ac : argument count
 * @av : list of arguments
 * @env : list of environment variables
 *
 * Return: 0 in success, -1 otherwise
 */

int main(int ac, char **av, char **env)
{
	size_t bufsize = 1024;
	char *b, *p = _getenv(env), *p1 = strdup(p);
	int status, pid;
	int isat = isatty(STDIN_FILENO);

	(void) ac;
	(void) av;
	do
	{
		if (isat == 1)
			printf("#cisfun$ ");
		b = malloc(bufsize);
		if (!b)
			return (-1);
		getline(&b, &bufsize, stdin);
		if (strcmp(b, "exit\n") == 0)
			break;
		pid = fork();
		if (pid == -1)
		{
			free(p1);
			free(b);
			exit(-1);
		}
		else if (pid == 0)
		{
			if (interactive(b, p1) == -1)
			{
				/* perror pending to be created */
			}
			exit(1);
		}
		else
			wait(&status);
	}while (isat == 1);
	free(p1);
	free(b);
	return (0);
}
