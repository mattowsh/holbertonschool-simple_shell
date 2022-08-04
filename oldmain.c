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
	char *b, *p, *p1, **baux = NULL;
	int status, pid, characters, i = 0, x = 0;
	int isat = isatty(STDIN_FILENO);

	(void) ac, (void) av;
	do {
		if (isat == 1)
			printf("#cisfun$ ");
		b = malloc(bufsize);
		if (!b)
			return (-1);
		characters = getline(&b, &bufsize, stdin);
		while (b[i] != '\n')
		{
			if ((separators(b[i]) == 0))
				break;
			i++;
		}
		if (b[i] == '\n')
		{
			free(b);
			if (isat == 1)
				continue;
			break;
		}
			
		if (characters == -1) /* EOF case */
		{
			massive_free(1, b);
			exit(errno);
		}

		baux = set_strtok(b);
		if (!baux[0])
		{
			free_grid(baux);
			free(b);
			return (0);
		}
		if ((strcmp(baux[0], "exit") == 0))
		{
			if (baux[1])
				x = atoi(baux[1]);
			free_grid(baux);
			free(b);
			exit(x);
		}
		pid = fork();
		if (pid == -1)
		{
			massive_free(1, b);
			exit(errno);
		}
		else if (pid == 0)
		{	
			p = _getenv(env);
			p1 = strdup(p);
			if (interactive(b, p1, env) == -1)
				perror(error(b));
			massive_free(3, b, p, p1);
			exit(errno);
		}
		else
		{
			wait(&status);
			free_grid(baux);
			free(b);
		}
		/*massive_free(3, b, p, p1);*/
	} while (isat == 1);
	/*massive_free(2, p1, b);*/
	return (0);
}
