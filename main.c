#include "main.h"


int non_interactive(char *p1, char **av)
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
		strcat(full_path, av[1]);
		if ((file = open(full_path, O_RDONLY)) == 3)
		{
			close(file);
			/*char *argv[] = { full_path, str_to_argv(av, " "), NULL };
			execve(full_path, argv, NULL);
		*/}
		p1 = strtok(NULL, ":");
		free(full_path);
	}
	return (-1);
}
int non_interactive1(char *p1, char *argv1, char *argv2, char *argv3)
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

int exists(char *filename)
{
	struct stat buffer;

	return (stat(filename, &buffer));
}
int interactive(char *b, char *p1)
{
	char *full_path;
	int file;
	char **argv;
	struct stat buf;

	printf("%s\n", p1);
	p1 = strtok(p1, ":");
	while (p1)
	{
		printf("%s\n", p1);
		full_path = malloc(1024);
		if (!full_path)
			return (-1);
		argv = set_strtok(b, " \n");
		strcat(full_path, p1);
		strcat(full_path, "/");
		strcat(full_path, argv[0]);
		printf("%s\n", full_path);
		for (int i = 0; argv[i]; i++)
			printf("%s\n", argv[i]);
		if (exists(full_path) == 0)
		{
			printf("found\n");
			execve(full_path, argv, NULL);
		}
		p1 = strtok(NULL, ":");
		free(full_path);
		free(argv);
	}
	return (-1);
}

int main(int ac, char **av, char **env)
{
	size_t bufsize = 1024;
	char *b;
	int characters;
	char *p = getenv("PATH");
	char *p1;
	int status, pid;

	if (ac > 1)
		return (non_interactive(p1, av));

	while(1)
	{
		if (!(b = malloc(bufsize)))
			return (-1);
		printf("#cisfun$ ");
		characters = getline(&b, &bufsize, stdin);
		if (!b)
		{
			free(b);
			continue;
		}
		if (strcmp(b, "exit\n") == 0)
		{
			free(b);
			return (0);
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
			printf("%s\n", p1);
			if (interactive(b, p1) == -1)
				perror("failed");
			free(b);
			exit(1);
		}
		else
			wait(&status);
		free(b);
	}
	return (0);
}
