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

	(void) env;
	if (ac > 1)
		return (non_interactive(p1, av));

	while(1)
	{
		if (!(b = malloc(bufsize)))
			return (-1);
		printf("#cisfun$ ");
		characters = getline(&b, &bufsize, stdin);
		b[characters - 1] = '\0';
		if (b[0] == '\0')
		{
			free(b);
			continue;
		}
		if (strcmp(b, "exit") == 0)
		{
			free(b);
			break;
		}
		pid = fork();
		p1 = strdup(p);
		if (pid == -1)
		{
			free(b);
			exit(1);
		}
		else if (pid == 0)
		{
			if (interactive(b, p1) == -1)
			{
				dprintf(STDERR_FILENO, "%s: %s: No such file or directory\n", av[0], b);
			}
			exit(1);
		}
		else
			wait(&status);
		free(b);
	}
	return (0);
}
