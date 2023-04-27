#include "shell.h"
/**
 * has_spaces - Check if the given string contains any spaces
 * @str: The string to check
 * Return: 1 if the string contains spaces, 0 otherwise
 */
int has_spaces(char *str)
{
	return (strchr(str, ' ') != NULL);
}

