#include "main.h"

/**
 * exists - Get the status of a file, checking if a filename exists or not
 * @filename : file to be checked
 *
 * Return: 0 in success, -1 otherwise
 */

int exists(char *filename)
{
	struct stat buffer;

	return (stat(filename, &buffer));
}
