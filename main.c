#include "main.h"
/**
 * main_aux0 - main auxiliar
 * @characters: int
 * @b: string
 * @not_found: int
 * @status: int
 */
void main_aux0(int characters, char *b, int not_found, int status)
{
	if (characters == -1)
	{
		free(b);
		if (not_found != 0)
			exit(not_found);
		exit(WEXITSTATUS(status));
	}
}
/**
 * main_aux_exit - handle exit command
 * @baux: pointer to strings
 * @not_found: edge cases
 * @status: int
 * Return: int
 */
int main_aux_exit(char **baux, int not_found, int status)
{
	if (strcmp(baux[0], "exit") == 0)
	{
		free_grid(baux);
		if (not_found != 0)
			exit(not_found);
		exit(WEXITSTATUS(status));
	}
	return (0);
}
/**
 * main_aux_env - function for env case
 * @baux: pointer to strings
 * Return: int
 */
int main_aux_env(char **baux)
{
	int i;

	if (strcmp(baux[0], "env") == 0)
	{
		for (i = 0; environ[i]; i++)
			printf("%s\n", environ[i]);
		free_grid(baux);
		return (1);
	}
	return (0);
}
/**
 * main_aux_fork - forks the funciton
 * @baux: char pointer to strings
 * @status: int
 * Return: int
 */
int main_aux_fork(char **baux, int status)
{
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
	return (status);
}
/**
 * main - Coordinates the execution of programs, creating
 * a child process if is necessary
 * @ac : argument count
 * @av : list of arguments
 *
 * Return: 0 in success, -1 otherwise
 */

int main(int ac, char **av)
{
	size_t bufsize = 1024;
	char *b = NULL, *b_tmp = NULL, *p = NULL, **baux = NULL, *full_path = NULL;
	int status = 0, characters, not_found = 0, isat = isatty(STDIN_FILENO);

	(void) ac, (void) av;
	while (1)
	{
		if (isat == 1)
			printf("#cisfun$ ");
		b = malloc(bufsize);
		if (!b)
			return (-1);
		characters = getline(&b, &bufsize, stdin);
		main_aux0(characters, b, not_found, status);
		b_tmp = strdup(b);
		strtok(b_tmp, "\n");
		baux = set_strtok(b_tmp);
		massive_free(2, b_tmp, b);
		if (!baux || !baux[0])
		{
			free_grid(baux);
			continue;
		}
		not_found = main_aux_exit(baux, not_found, status);
		if (main_aux_env(baux))
			continue;
		p = _getenv("PATH");
		full_path = _which(p, baux);
		if (full_path == 0)
		{
			not_found = 127;
			dprintf(STDERR_FILENO, "./hsh: 1: %s: not found\n", baux[0]);
		}
		massive_free(2, p, baux[0]);
		baux[0] = full_path;
		if (main_aux_1(baux))
			continue;
		status = main_aux_fork(baux, status);
	}
	return (0);
}
