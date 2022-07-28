#include "main.h"



int main(void)
{
	char p[] = {"hi world and goodbye world or smthn"};
	char ***result = set_strtok(p, " ");
	int i, j;

	for (i = 0; (*result)[i]; i++)
	{
		printf("%s\n", (*result)[i]);
	}

	return (0);
}
