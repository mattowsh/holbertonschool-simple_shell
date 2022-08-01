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
	int i, j, k, l, letters, counter;

	i = j = k = l = letters = counter = 0;
	if (input == NULL || *input == '\0')
		return (NULL);

	/* to calculate the number of words in my input */
	while (input[i])
	{
		if ((input[i+1] == ' ' || input[i+1] == '\n' || input[i+1] == '\t' || input[i+1] == '\0')
		&& (input[i] != ' ' && input[i] != '\n' && input[i] != '\t' && input[i] != '\0'))
			counter++;
		i++;
	}

	result = malloc(sizeof(char *) * (counter + 1));
	if (result == NULL)
		return (NULL);

	/* j = counter that counts EVERY byte in my input string */
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
