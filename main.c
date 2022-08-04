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
	char *b, *p, *p1, **baux = NULL, *full_path;
	int status, pid, characters, x = 0;
	int isat = isatty(STDIN_FILENO);

	(void) ac, (void) av;
	do {
		if (isat == 1)
			printf("#cisfun$ ");

		b = malloc(bufsize);
		if (!b)
			return (-1);
		characters = getline(&b, &bufsize, stdin);
		/*while (b[i] != '\n')
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
		}*/
		if (characters == -1) /* EOF case */
		{
			massive_free(1, b);
			exit(errno);
		}

		b = strtok(b, "\n");
		baux = set_strtok(b);
		if (!baux[0])
		{
			free_grid(baux);
			return (0);
		}
		if ((strcmp(baux[0], "exit") == 0))
		{
			if (baux[1])
				x = atoi(baux[1]);
			free_grid(baux);
			massive_free(1, b);
			exit(x);
		}

		p = _getenv(env);
		if (!p)
		{
			massive_free(1, p);
			exit(errno);
		}
		p1 = strdup(p);
		full_path = interactive(b, p1);
		if (!full_path)
		{
			free_grid(baux);
			massive_free(3, b, p, p1);
			continue;
		}
		pid = fork();
		if (pid == -1)
		{
			massive_free(4,full_path, b, p, p1);
			exit(errno);
		}
		else if (pid == 0)
		{	
			execve(full_path, baux, env);
			/*if (interactive(b, p1, env) == -1)
				perror(error(b));
			*/massive_free(4,full_path, b, p1);
			free_grid(baux);
			exit(errno);
		}
		else
		{
			wait(&status);
			massive_free(3,full_path, b, p1);
			free_grid(baux);
		}
		/*massive_free(3, b, p, p1);*/
	} while (isat == 1);
	/*massive_free(2, p1, b);*/
	return (0);
}
