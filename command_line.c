#include "shell.h"

/**
 * main - write a UNIX command line interpreter
 * @argc: number of arguments passed to the program
 * @argv: array of pointers to the arguments.
 * Return: always 0
 */

int main(int argc, char **argv)
{
	char *string = "(Moshonor)& ";
	char *linept;
	size_t sizeb = 0;
	ssize_t nwechar_read;

	/**making agrc and argv void**/

	(void)argc, (void)argv;
	while (1)
	{
		write(STDOUT_FILENO, string, strlen(string));
		nwechar_read = getline(&linept, &sizeb, stdin);

		if (nwechar_read == -1)
		{
			perror("Exit the shell----\n");
			return (-1);
			free(linept);
		}
		write(STDOUT_FILENO, linept, nwechar_read);
	}
	return (0);
}
