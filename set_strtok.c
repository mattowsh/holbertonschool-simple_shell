#include "main.h"



char **set_strtok(char *input, char *sep)
{
	char *in = input;
	char *in1 = strdup(in);
	char *in2 = strdup(in);
	char **result;
	int i, len, j = 0;

	in2 = strtok(in2, sep);
	while (in2)
	{
		j++;
		in2 = strtok(NULL, sep);
	}
	free(in2);
	if (j == 0)
		return (0);

	result = malloc(sizeof(char *) * (j + 1));
	if (!(result))
		return (0);

	in1 = strtok(in1, sep);
	for (i = 0; i < j; i++)
	{
		len = strlen(in1);
		result[i] = malloc(len++);
		if (!(result[i]))
		{
			free(in1);
			for (; i >= 0; i--)
				free(result[i]);
			free(result);
			free(in1);
			return (0);
		}
		result[i] = strdup(in1);
		in1 = strtok(NULL, sep);
	}
	result[++i] = NULL;
	free(in1);
	return (result);
}
/*

int main(void)
{
	char **argv;
	char *p = "hola todo bien\n";
	int i;

	argv = set_strtok(p, " \n");
	for (i = 0; argv[i]; i++)
		printf("%s\n", argv[i]);

	for (; i >= 0; i--)
		free(argv[i]);
	free(argv);
	free(p);
	return (0);
}
*/
