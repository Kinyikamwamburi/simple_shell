#include "simple_shell.h"
/**
 * _execve - execute all the commands
 * @prompt: the command to execute
 * @fileName: executable file name
 * @env: enviroment variables
 *
 * Return: is a void
 */
void _execve(char *prompt, char *fileName, char **env)
{
	char **argum;

	argum = _sortArguments(prompt, fileName);

	checkHelp(argum[0],  argum[1]);

	if (_strcmp(argum[0], "cd") != 0)
	{
		if (execve(buildPath(argum, fileName, env), argum, env) == -1)
			showError(argum, fileName);
	}

	free(argum);

	exit(0);
}
/**
 * get_env_value - get the enviroment var value
 * @nameVar: name var
 * @env: enviroment variables
 *
 * Return: pointer to the value
 */
char *get_env_value(char *nameVar, char **env)
{
	int cnt = 0;
	char *arguments, **cpyEnv = copyEnv(env);

	arguments = strtok(cpyEnv[cnt], "=");

	while (env[cnt])
	{
		if (_strcmp(arguments, nameVar) == 0)
		{
			arguments = strtok(NULL, "\n");
			return (arguments);
		}

		cnt++;
		arguments = strtok(cpyEnv[cnt], "=");
	}

	return (NULL);
}
/**
 * env_split - split the value of the enviroment var
 * @path_value: pointer to the value
 * @command: command to concat
 * @fileName: executable file name
 *
 * Return: the complete path
 */
char *env_split(char *path_value, char *command, char *fileName)
{
	int lenCommand = 0, lenPath = 0, _mallocsize;
	char *valuePath = strtok(path_value, ":"), *pathDir;
	struct stat stat_var;

	lenCommand = lengthArray(command);
	lenPath = lengthArray(valuePath);
	_mallocsize = lenCommand + lenPath + 1;

	while (valuePath != NULL)
	{
		pathDir = malloc(sizeof(char) * (_mallocsize));
		if (pathDir == NULL)
			perror(fileName);

		_strcat(pathDir, valuePath);
		_strcat(pathDir, "/");
		_strcat(pathDir, command);
		*(pathDir + _mallocsize) = '\0';

		if (stat(pathDir, &stat_var) == 0)
			return (pathDir);

		free(pathDir);

		valuePath = strtok(NULL, ":");
	}

	return (NULL);
}

/**
 * checkHelp - check if is a help command
 * @command: command to validate
 * @arg: command's arguments
 *
 */
void checkHelp(char *command, char *arg)
{
	if (_strcmp(command, "help") == 0)
	{
		if (_strcmp("cd", arg) == 0)
		{
			read_textfile("help_cd", 1576);
		}
		else if (_strcmp(arg, "exit") == 0)
		{
			read_textfile("help_exit", 152);
		}
		else if (_strcmp(arg, "alias") == 0)
		{
			read_textfile("help_alias", 567);
		}
		else if ((_strcmp(arg, "help") == 0))
		{
			read_textfile("help_help", 643);
		}
		exit(0);
	}
}

/**
 *checkCd - chek if is a cd command
 *@command: command to validate
 *@arg: command's argument
 *
 */
void checkCd(char *command, char *arg)
{
	if (_strcmp(command, "cd") == 0)
	{
		if (arg != NULL)
		{
			if (chdir(arg) != 0)
			{
				perror(command);
			}
		}
	}
}
