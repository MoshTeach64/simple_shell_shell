#ifndef _SHELL_H_
#define _SHELL_H_

#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
#include <stdio.h>

void prompt(void);
ssize_t read_command(char **lineptr, size_t *buff_size);
int has_spaces(char *str);
void execute_command(char *command, char **argv, char **envp);

#endif
