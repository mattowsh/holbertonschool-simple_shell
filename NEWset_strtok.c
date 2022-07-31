#include "main.h"



char **set_strtok(char *input)
{
	char **result;
	int i, k, letters, j, l, counter = 0;

	i = 0;

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

	/*printf("COUNTER PALABRAS: %i\n", counter);*/
	result = malloc(sizeof(char *) * (counter + 1));
	if (result == NULL)
		return (NULL);

	j = 0; /* j = counter that counts EVERY byte in my input string */
	for (i = 0; (i < counter) && input[j]; i++)
	{
		letters = 0;
		while (input[j] == ' ' || input[j] == '\n' || input[j] == '\t' || input[j] == '\0')
			j++;
		while (input[j] != ' ' && input[j] != '\n' && input[j] != '\t' && input[j] != '\0')
		{
			/*printf("j: >>%c<< // letters: >>%i<<\n", input[j], letters);*/
			letters++, j++;
		}

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
