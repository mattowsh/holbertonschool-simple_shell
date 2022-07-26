#include "main.h"

char **str_to_argv(char *input, )
{
	char **result;

	malloc
}


int non_interactive(char *p1, char *argv1, char *argv2, char *argv3)
{
	char *full_path;
	int file;

	p1 = strtok(p1, ":");
	while (p1)
	{
		if (!(full_path = malloc(1024)))
			return (-1);
		strcat(full_path, p1);
		strcat(full_path, "/");
		strcat(full_path, argv1);
		if ((file = open(full_path, O_RDONLY)) == 3)
		{
			close(file);
			char *argv[] = { full_path, argv2, argv3, NULL };
			execve(full_path, argv, NULL);
		}
		p1 = strtok(NULL, ":");
		free(full_path);
	}
	return (-1);
}

int interactive(char *b, char *p1)
{
	char *full_path;
	int file;
	int i = 0;

	p1 = strtok(p1, "-");
	while (p1)
	{
		if (!(full_path = malloc(1024)))
			return (-1);
		strcat(full_path, p1);
		strcat(full_path, "/");
		if ((file = open(full_path, O_RDONLY)) == 3)
		{
			close(file);
			execve(full_path, b, NULL);
		}
		p1 = strtok(NULL, ":");
		free(full_path);
	}
	return (-1);
}

int main(int ac, char **av, char **env)
{
	size_t bufsize = 1024;
	char *b;
	int characters;
	char *p = getenv("PATH");
	char *p1 = strdup(p);
	int fr;
	int status, pid;

	if (ac > 1)
		return (non_interactive(p1, av[1], av[2], av[3]));

	while(1)
	{
		if (!(b = malloc(bufsize)))
			return (-1);
		printf("#cisfun$ ");
		characters = getline(&b, &bufsize, stdin);
		
		switch (pid = fork())
		{
			case -1:
				exit(-1);
				break;
			case 0: /*Proceso hijo*/

				break;
			default: /*Proceso padre*/
				wait(&status);
				break;
		}
		free(b);
	}
	return (0);
}
