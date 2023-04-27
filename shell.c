#include "shell.h"
/**
 * main - Entry point for the shell program
 * @argc: Argument count
 * @argv: Array of command-line arguments
 * @envp: Environment variables pointer
 * Return: Always 0 on success
 */
int main(int argc, char **argv, char **envp)
{
	char *lineptr = NULL;
	size_t buff_size = 0;
	/*ssize_t n = 0;*/
	(void)argc;
	while (1)
	{
		prompt();
		read_command(&lineptr, &buff_size);
		if (has_spaces(lineptr))
		{
			perror("./shell: No such file or directory");
			continue;
		}
		execute_command(lineptr, argv, envp);
	}
	free(lineptr);
	return (0);
}
