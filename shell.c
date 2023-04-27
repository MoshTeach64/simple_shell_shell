#include "shell.h"
/**
 * main - Entry point for the shell program
 * @argc: Argument count
 * @argv: Array of command-line arguments
 * @envp: Environment variables pointer
 * Return: Always 0 on success
 */
int main(void)
{
    char *line = NULL;
    size_t bufsize = 0;
    int status;

    while (1) {
        printf("#cisfun$ ");
        if (getline(&line, &bufsize, stdin) == -1) {
            if (feof(stdin)) {  // end of file condition (ctrl-d)
                printf("\n");
                exit(EXIT_SUCCESS);
            } else {
                perror("getline");
                exit(EXIT_FAILURE);
            }
        }

        line[strlen(line) - 1] = '\0';  // remove the newline character

        if (strcmp(line, "exit") == 0) {
            break;
        }

        pid_t pid = fork();

        if (pid == 0) {
            char *argv[] = {line, NULL};
            if (execve(argv[0], argv, NULL) == -1) {
                perror("execve");
            }
            exit(EXIT_FAILURE);
        } else if (pid < 0) {
            perror("fork");
        } else {
            do {
                waitpid(pid, &status, WUNTRACED);
            } while (!WIFEXITED(status) && !WIFSIGNALED(status));
        }
    }

    free(line);
    exit(EXIT_SUCCESS);
}
