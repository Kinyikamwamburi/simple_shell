#ifndef SIMPLE_SHELL_H
#define SIMPLE_SHELL_H

/* LIBRARIES */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdarg.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include<sys/wait.h>
#include <signal.h>


/* MACROS */
#define MSJ_SIZE 1

/* FUNCTIONS */
int _putchar(char c);
char *_prompt(int status_iss, char *fileName);
void delete_newline(char **prompt);
void _execve(char *prompt, char *fileName, char **env);
int _strcmp(char *s1, char *s2);
char *_strcpy(char *dest, char *src);
int countSpace(char *prompt);
char *get_env_value(char *nameVar, char **env);
int lengthArray(char *array);
char *_strcat(char *dest, char *src);
char *get_env_value(char *nameVar, char **env);
char *env_split(char *path_value, char *command, char *fileName);
void exitValidation(char *prompt);
void ctrlcValidate(void);
void newPrompt(int _signal);
char **copyEnv(char **env);
void freeDoubleArray(char **arg);
int _print_numbers_recursion(int number);

ssize_t read_textfile(const char *filename, size_t letters);
void checkHelp(char *command, char *arg);
void checkCd(char *command, char *arg);
char **_sortArguments(char *prompt, char *fileName);
void _execve2(char *prompt, char *fileName);
void showError(char **arg, char *fileName);
int countArguments(char **arg);
char *buildPath(char **argum, char *nameFile, char **env);

#endif /* SIMPLE_SHELL_H */
