#include "shell.h"

/**
  * prompt_user - prints prompt for user
  */
void prompt_user(void)
{
	if (isatty(STDIN_FILENO))
		printf("~$ ");
}

/**
  * read_input - reads input from user
  * @buffer: buffer to store input
  * @bufsize: size of buffer
  * Return: number of characters read
  */
int read_input(char **buffer, size_t *bufsize)
{
	return (getline(buffer, bufsize, stdin));
}

/**
  * handle_input - handles user input
  * @av: argument vector
  * @envp: array of environment variables
  * Return: 1 if handled successfully, 0 otherwise
  */
int handle_input(char **av, char **envp)
{
	int status;
	pid_t child_pid;

	if (!av[0])
	{
		free(av);
		return (1);
	}
	if (_strcmp(av[0], "env") == 0)
	{
		print_environ(), free(av);
		return (1);
	}
	if (_strcmp(av[0], "exit") == 0)
		free(av), exit(0);
	child_pid = fork();
	if (child_pid == 0)
	{
		if (_strchr(av[0], '/') == NULL)
			av[0] = path_search(av[0]);
		if (execve(av[0], av, envp))
		{
			perror("./shelley"), exit(EXIT_FAILURE);
			return (0);
		}
	}
	wait(&status), free(av);
	return (1);
}

/**
  * main - entry point of the program
  * @ac: argument counter
  * @av: argument vector
  * @envp: array of strings.
  * Return: 0
  */
int main(int ac __attribute__((unused)), char *av[], char *envp[])
{
	char *buffer = NULL;
	size_t bufsize = 0;

	signal(SIGINT, SIG_IGN);
	while (1)
	{
		prompt_user();
		if (read_input(&buffer, &bufsize) == -1)
			break;
		if (buffer == NULL)
			exit(0);
		av = parse_input_string(buffer);
		if (!handle_input(av, envp))
			break;
	}
	free(buffer);
	return (0);
}

