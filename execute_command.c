#include "shell.h"

/**
 * execute_command - Execute a command
 * @command: The command to execute
 * @argv: Array of command-line arguments
 * @envp: Environment variables pointer
 */
void execute_command(char *command, char **argv, char **envp)
{
	pid_t pid = fork();
	int status;

	if (pid == -1)
	{
		perror("./shell: No such file or directory");
		exit(EXIT_FAILURE);
	}
	else if (pid == 0)
	{
		/* child process */
		if (execve(command, argv, envp) == -1)
		{
			/* execve failed */
			/*perror("./shell: No such file or directory");*/
			exit(EXIT_FAILURE);
		}
	}
	else
	{
		/* parent process */
		waitpid(pid, &status, 0);
		if (WIFEXITED(status) && WEXITSTATUS(status) != 0)
		{
			perror("./shell: No such file or directory");
		}
	}
}
