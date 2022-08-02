#include "main.h"



void massive_free(int n, ...)
{
	va_list p0;
	int i;

	va_start(p0, n);
	for (i = 0; i < n; i++)
	{
		free(va_arg(p0, char *));
	}
	va_end(p0);
}
