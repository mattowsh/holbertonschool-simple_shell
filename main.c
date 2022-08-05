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

int main(int ac, char **av)
{
	size_t bufsize = 1024;
	char *b = NULL, *p = NULL, **baux = NULL, *full_path = NULL;
	int status = 0, characters, i, not_found = 0;
	int isat = isatty(STDIN_FILENO);

	(void) ac, (void) av;
	while(1)
	{
		if (isat == 1)
			printf("#cisfun$ ");
		b = malloc(bufsize);
		if (!b)
			return (-1);
		characters = getline(&b, &bufsize, stdin);
		if (characters == -1) /* EOF case */
		{
			massive_free(1, b);
			if (not_found != 0)
				exit(not_found);
			exit(WEXITSTATUS(status));
		}
		b = strtok(b, "\n");
		baux = set_strtok(b);
		free(b);
		if (!baux || !baux[0])
		{
			free_grid(baux);
			continue;
		}
		if (strcmp(baux[0], "exit") == 0)
		{
			free_grid(baux);
			if (not_found != 0)
				exit(not_found);
			exit(WEXITSTATUS(status));
		}
		not_found = 0;
		if (strcmp(baux[0], "env") == 0)
		{
			for (i = 0; environ[i]; i++)
				printf("%s\n", environ[i]);
			free_grid(baux);
			continue;
		}
		p = _getenv("PATH");
		full_path = _which(p, baux);
		if (full_path == 0)
		{
			not_found = 127;
			dprintf(STDERR_FILENO, "./hsh: 1: %s: not found\n", baux[0]);
		}
		free(p);
		free(baux[0]);
		baux[0] = full_path;
		if (!baux[0])
		{
			free_grid(baux);
			continue;
		}
		if (fork() == 0)
		{
			if (execve(baux[0], baux, environ) == -1)
				perror("Error:");
		}
		else
		{
			wait(&status);
			free_grid(baux);
		}
		/*massive_free(3, b, p, p1);*/
	}
	/*massive_free(2, p1, b);*/
	return (0);
}
