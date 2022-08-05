#include "main.h"

/**
 * main_aux_1 - Checks if we receive or not arguments
 * @baux : list of arguments
 *
 * Return: 1 if we don't receive arguments, 0 otherwise
 */

int main_aux_1(char **baux)
{
	if (!baux[0])
	{
		free_grid(baux);
		return (1);
	}
	return (0);
}

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
