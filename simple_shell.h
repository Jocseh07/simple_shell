#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <fcntl.h>

int execute(char **args);
char **parse_string(char *line, char *sep);
char *get_path(char *command);
int empty_line(char *line);
void print_env(void);
char *get_env(char *env_var);
int _strcmp(char *s1, char *s2);
char *_strcat(char *dest, char *src);
char *_strcpy(char *dest, char *src);
int _strlen(char *s);
int simple_shell(void);
int check_command(char *command);

extern char **environ;

#endif
