#ifndef MAIN_H
#define MAIN_H
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <sys/wait.h>
#include <stdarg.h>

/**
 * struct separators - Contains char separators to the separators function
 * @sep : char separators: space, newline, tab and final NULL of a string
 */

typedef struct separators
{
	char *sep;
} separators_t;

/* functions */
char **set_strtok(char *input);
int exists(char *filename);
int non_interactive(char *p1, char **av);
int interactive(char *b, char *p1);
int separators(char letter);
char *_getenv(char **env);
void massive_free(int n, ...);
#endif
