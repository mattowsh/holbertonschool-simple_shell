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
	char *b = NULL, *p = NULL, **baux = NULL, *full_path = NULL;
	int status, characters, x = 0;
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
		b = strtok(b, "\n");	
		if (characters == -1) /* EOF case */
		{
			massive_free(1, b);
			exit(errno);
		}

		baux = set_strtok(b);
		free(b);
		if (!baux || !baux[0])
		{
			free_grid(baux);
			continue;
		}
		if ((strcmp(baux[0], "exit") == 0))
		{
			if (baux[1])
				x = atoi(baux[1]);
			free_grid(baux);
			exit(x);
		}
		if (exists(baux[0]) != 0)
		{
			p = _getenv(env);
			full_path = _which(p, baux);
			if (full_path == 0)
				dprintf(STDERR_FILENO, "./hsh: %s not found\n", baux[0]);
			free(p);
			free(baux[0]);
			baux[0] = full_path;
		}
		if (!baux[0])
		{
			free_grid(baux);
			continue;
		}
		if (fork() == 0)
		{
			if (execve(baux[0], baux, env) == -1)
				perror("Error:");
			free_grid(baux);
			exit(errno);
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
