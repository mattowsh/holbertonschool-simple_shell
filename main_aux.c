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
 * main_aux0 - Checks main getline return. Case: EOF input
 * @characters : main getline return
 * @b : input
 * @not_found : error int
 * @status: status variable, int
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
 * main_aux_exit - Handles the "exit" built it
 * @baux : list of arguements
 * @not_found : error int
 * @status: status variable, int
 *
 * Return: 0 if the argument is not "exit", != 0 otherwise
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
 * main_aux_env - Handles the "env" built it
 * @baux : list of arguments
 *
 * Return: 1 if the argument is "env", 0 if is not
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
 * main_aux_fork - Creates a child process
 * @baux : list of arguments
 * @status : status variable, int
 *
 * Return: child process status value
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
