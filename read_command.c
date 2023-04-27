#include "shell.h"
/**
 * read_command - Read a command from standard input
 * @lineptr: Pointer to the buffer where the command will be stored
 * @buff_size: Pointer to the buffer size
 * Return: The number of characters read, or -1 on failure
 */
ssize_t read_command(char **lineptr, size_t *buff_size)
{
        ssize_t n = 0;

       n = getline(lineptr, buff_size, stdin);
        if (n == -1)
        {
                if (feof(stdin))
                {
                        /* end of file has been reached */
                        exit(EXIT_SUCCESS);
                }
                else
                {
                        /* error reading from stdin */
                        perror("./shell: No such file or directory");
                        exit(EXIT_FAILURE);
                }
        }
        if ((*lineptr)[n - 1] == '\n')
        {
                /* replace the newline char with '\0' */
                (*lineptr)[n - 1] = '\0';
        }
        return n;
}
