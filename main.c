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
	char *b, *p = _getenv(env), *p1;
	int status, pid, characters;
	int isat = isatty(STDIN_FILENO);

	(void)ac;
	(void)av;
	do
	{
		p1 = strdup(p);
		if (isat == 1)
			printf("#cisfun$ ");
		b = malloc(bufsize);
		if (!b)
			return (-1);
		characters = getline(&b, &bufsize, stdin); /* when ctrl+D*/
		if (characters == -1)
			exit(-1);
		if (strcmp(b, "exit\n") == 0)
			break;
		pid = fork();
		if (pid == -1)
		{
			massive_free(2, p1, b);
			exit(-1);
		}
		else if (pid == 0)
		{
			if (interactive(b, p1) == -1)
			{
				/* perror pending to be created */
			}
			massive_free(2, p1, b);
			exit(1);
		}
		else
			wait(&status);
		massive_free(2, p1, b);
	}while (isat == 1);
	massive_free(2, p1, b);
	return (0);
}
