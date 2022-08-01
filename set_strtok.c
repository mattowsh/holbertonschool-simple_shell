#include "main.h"

/**
 * set_strtok - Tokenize a string based in separators:
 * space, newline, tab or NULL character at the end of the string
 * @input: string to be tokenized
 *
 * Return: a pointer to the matrix that contains the tokens
 */

char **set_strtok(char *input)
{
	char **result;
	int i = 0, j = 0, k = 0, l = 0, letters, counter = 0;

	if (input == NULL || *input == '\0')
		return (NULL);

	while (input[i])
	{
		if ((separators(input[i + 1]) == 1) && ((separators(input[i])) != 1))
			counter++;
		i++;
	}
	result = malloc(sizeof(char *) * (counter + 1));
	if (result == NULL)
		return (NULL);

	for (i = 0; (i < counter) && input[j]; i++)
	{
		letters = 0;
		while (input[j] == ' ' || input[j] == '\n' || input[j] == '\t' || input[j] == '\0')
			j++;
		while (input[j] != ' ' && input[j] != '\n' && input[j] != '\t' && input[j] != '\0')
			letters++, j++;

		result[i] = malloc(letters + 1);
		if (!result[i])
			return (NULL);

		result[i][letters] = '\0';
		k = j;
		l = letters - 1;
		for (; k > (j - letters); k--, l--)
			result[i][l] = input[k - 1];
	}
	result[counter] = NULL;
	return(result);
}

/*int main(void)
{
	char **argv;
	char *p = "hola todo bien   ";
	int i;
	printf("p: >>%s<<\n", p);
	argv = set_strtok(p);
	for (i = 0; argv[i]; i++)
		printf("%s\n", argv[i]);
	return (0);
}*/
