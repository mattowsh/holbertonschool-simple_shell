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
	if (j == 0)
		return (0);
	in1 = strdup(in);

	result = malloc(sizeof(char *) * (j + 1));
	if (!(result))
		return (0);

	printf("first success\n");
	in1 = strtok(in1, sep);
	for (i = 0; i < j; i++)
	{
		printf("second success\n");
		len = strlen(in1);
		result[i] = malloc(len++);
		printf("third success");
		if (!(result[i]))
		{
			printf("error");
			for (; i >= 0; i--)
				free(result[i]);
			free(result);
		}
		printf("fourth success\n");
		result[i] = strdup(in1);
		in1 = strtok(NULL, sep);
	}
	result[++i] = 0;
	return (result);
}
