#include "main.h"



int mul_extecutions(char *b)
{
	int counter = 0;
	int i;

	for (i = 0; b[i]; i++)
	{
		if (b[i] == '\n')
			counter++;
	}
	return (counter);
}
