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
	char *b, *p = getenv("PATH"), *p1 = strdup(p);
	int status, characters, pid;
	int isat = isatty(STDIN_FILENO);

	(void) env;
	while (1)
	{
		if (isat == 1)
			printf("#cisfun$ ");
		b = malloc(bufsize);
		if (!b)
			return (-1);
		characters = getline(&b, &bufsize, stdin);
		if (strcmp(b, "exit\n") == 0)
			break;
		pid = fork();
		p1 = strdup(p);
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
		if (isat != 1)
			break;
	}
	free(p1);
	free(b);
	return (0);
}
