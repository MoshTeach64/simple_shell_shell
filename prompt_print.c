#include "shell.h"

/**
 * prompt - Print the shell prompt
 */
void prompt(void)
{
        char buf[] = "Ezeonor:& ";
        if (isatty(STDIN_FILENO) == 1)
        {
                write(STDOUT_FILENO, buf, sizeof(buf) - 1);
        }
}
