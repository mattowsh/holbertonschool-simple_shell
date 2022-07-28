#include "lists.h"



char ***set_strtok(char **input, char *sep)
{
	char **in = input;
	char **in1 = strdup(in);
	char **temp = strdup(in);;
	int i, len, j = 0;

	in1 = strtok(in1, sep);
	while (in1)
	{
		j++;
		in1 = strtok(NULL, sep);
	}
	if (j == 0)
		return (0);

	in1 = strdup(in);

	(*result) = malloc(sizeof(char * j));
	if (!(*result))
		return (0);

	in1 = strtok(in1, sep);
	temp = strtok(in1, sep);
	for (i = 0; (*result)[i]; i++)
	{
		if ((temp = strtok(NULL, sep)) == NULL)
			in1 = strtok(in1, "\n");
		len = strlen(in1);
		(*result)[i] = malloc(len);
		if (!(*result)[i])
		{
			for (; i >= 0; i--)
				free((*result)[i]);
			free(*result);	
		}
		(*result)[i] = strdup(in1);
		in1 = strtok(NULL, sep);
	}

	return (result);
}
