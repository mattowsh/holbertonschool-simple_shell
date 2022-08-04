#include "main.h"

/**
 * exists - Get the status of a file, checking if a filename exists or not
 * @filename : file to be checked
 *
 * Return: 0 in success, -1 otherwise
 */

int exists(char *filename)
{
	struct stat buffer;

	return (stat(filename, &buffer));
}

/**
 * non_interactive - Executes the non-interactive shell mode
 * from child process
 * @p1 : the value of environment variable PATH
 * @av : list of arguments
 *
 * Return: -1 if the execution failed
 */

int non_interactive(char *p1, char **av, char **env)
{
	char *full_path, *temp;
	char **argv;
	int file = 0, i = 0;

	p1 = strtok(p1, ":");
	while (p1)
	{
		full_path = malloc(1024);
		if (!full_path)
			return (-1);

		if (exists(av[1]) != 0)
		{
			strcat(full_path, p1);
			strcat(full_path, "/");
		}
		strcat(full_path, av[1]);

		file = open(full_path, O_RDONLY);
		if (file == 3)
		{
			close(file);
			temp = malloc(1024);
			if (!temp)
				return (-1);
			strcat(temp, full_path);
			for (i = 1; av[i]; i++)
			{
				strcat(temp, av[i]);
				strcat(temp, " ");
			}
			argv = set_strtok(temp);
			free(temp);
			execve(full_path, argv, env);
		}
		p1 = strtok(NULL, ":");
		free_grid(argv);
		free(full_path);
	}
	return (-1);
}

/**
 * interactive - Executes the interactive shell mode
 * from child process
 * @b : interactive shell input
 * @p1 : the value of environment variable PATH
 *
 * Return: -1 if the execution failed
 */

int interactive(char *b, char *p1, char **env)
{
	char *tokens, *full_path, **argv = NULL;

	tokens = strtok(p1, ":");
	while (tokens != NULL)
	{
		full_path = malloc(1024);
		if (!full_path)
			return (-1);

		if (argv)
			free_grid(argv);
		argv = set_strtok(b);

		if (exists(argv[0]) == 0) /*if b = absolut path*/
			execve(argv[0], argv, env);

		full_path[0] = 0;
		strcat(full_path, tokens);
		strcat(full_path, "/");
		strcat(full_path, argv[0]);
		strcat(full_path, "\0");
		if (exists(full_path) == 0)
			execve(full_path, argv, env);
		tokens = strtok(NULL, ":");
		free_grid(argv);
		free(full_path);
	}
	return (-1);
}
