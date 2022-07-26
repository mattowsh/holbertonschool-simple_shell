#include "main.h"

int main(int ac, char **av, char **env)
{
	size_t bufsize = 256;
	char buffer[bufsize];
	char *b = buffer;
	int characters;
	char *p = getenv("PATH");
	char *p1 = strdup(p);
	int file;
	char *full_path;
	if (ac > 1)
	{
		p1 = strtok(p1, ":");
		while (p1)
		{
			if (!(full_path = malloc(1024)))
				return(0);
			strcat(full_path, p1);
			strcat(full_path, "/");
			strcat(full_path, av[1]);
			if ((file = open(full_path, O_RDONLY)) == 3)
			{
				char *argv[] = { full_path, av[2] };
				execve(full_path, argv, NULL);
			}
			close(file);
			p1 = strtok(NULL, ":");
			free(full_path);
		}
		return (0);
	}

	while(1)
	{
		printf("($) ");
		characters = getline(&b, &bufsize, stdin);
	}
	return (0);
}
