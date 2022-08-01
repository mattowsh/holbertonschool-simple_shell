#ifndef MAIN_H
#define MAIN_H
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <sys/wait.h>

/* structure */
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

#endif
