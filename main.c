#include "main.h"


int exists(char *filename)
{
	struct stat buffer;
	return (stat(filename, &buffer));
}

int non_interactive(char *p1, char **av)
{
	char *full_path;
	int file;
	char *temp;
	int i;
	char **argv;

	p1 = strtok(p1, ":");
	while (p1)
	{
		if (!(full_path = malloc(1024)))
			return (-1);
		if (exists(av[1]) != 0)
		{
			strcat(full_path, p1);
			strcat(full_path, "/");
		}
		strcat(full_path, av[1]);
		if ((file = open(full_path, O_RDONLY)) == 3)
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
			execve(full_path, argv, NULL);
		}
		p1 = strtok(NULL, ":");
		free(full_path);
	}
	return (-1);
}
int interactive(char *b, char *p1)
{
	char *tokens;
	char *full_path;
	char **argv = NULL;

	tokens = strtok(p1, ":");
	while (tokens != NULL)
	{
		full_path = malloc(1024);
		if (!full_path)
			return (-1);

		if (argv)
			free(argv);
		argv = set_strtok(b);

		if (exists(argv[0]) == 0) /*if b = ruta absoluta (ej. /bin/ls)*/
			execve(argv[0], argv, NULL);
		
		/* si antes checkeo que b != ruta absoluta valida...*/
		strcat(full_path, tokens);
		strcat(full_path, "/");
		strcat(full_path, argv[0]);
		strcat(full_path, "\0");
		if (exists(full_path) == 0)
			execve(full_path, argv, NULL);
		tokens = strtok(NULL, ":");
		free(full_path);
	}
	return (-1);
}

int main(int ac, char **av, char **env)
{
	size_t bufsize = 1024;
	char *b, *error_message;
	int characters;
	char *p = getenv("PATH");
	char *p1 = strdup(p);
	int status, pid;

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
