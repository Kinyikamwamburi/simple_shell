
#include "simple_shell.h"
/**
 * _execve2 - execute all the commands
 * @prompt: the command to execute
 * @fileName: executable file name
 *
 * Return: is a void
 */
void _execve2(char *prompt, char *fileName)
{
	char **argum;

	argum = _sortArguments(prompt, fileName);
	checkCd(argum[0], argum[1]);
}
/**
 * _sortArguments - sort arguments
 * @prompt: the command to execute
 * @fileName: executable file name
 *
 * Return: **pointer
 */
char **_sortArguments(char *prompt, char *fileName)
{
	char *arguments, **argum;
	int cnt = 0, sizeArgum;

	sizeArgum = countSpace(prompt);
	argum = malloc(sizeof(char *) * ++sizeArgum);
	if (argum == NULL)
		perror(fileName);
	arguments = strtok(prompt, " \t\n\r");
	while (arguments != NULL)
	{
		argum[cnt++] = arguments;
		arguments = strtok(NULL, " \t\n\r");
	}
	argum[cnt] = NULL;
	return (argum);
}
/**
 * _printf_numbers_recursion - Funtion value number.
 * @number: Value int.
 *
 * Return: cnt.
 */
int _printf_numbers_recursion(unsigned int number)
{
	unsigned int new_number = number / 10;
	unsigned int prt_number = number % 10;
	unsigned int cnt = 0;

	if (new_number != 0)
	{
		cnt += _printf_numbers_recursion(new_number);
		cnt++;
		_putchar('0' + prt_number);
	}
	else
	{
		cnt++;
		_putchar('0' + number);
	}

	return (cnt);
}
/**
 * _printf_numbers_recursion - Funtion value number.
 * @number: Value int.
 *
 * Return: cnt.
 */
int _print_numbers_recursion(int number)
{
	int new_number = number / 10;
	int prt_number = number % 10;
	int cnt = 0;

	if (new_number != 0)
	{
		cnt += _print_numbers_recursion(new_number);
		cnt++;
		_putchar('0' + prt_number);
	}
	else
	{
		cnt++;
		_putchar('0' + number);
	}

	return (cnt);
}

char *buildPath(char **argum, char *fileName, char **env)
{
	char *path_val, *pathEnv;
	struct stat stat_var;

	if (!stat(argum[0], &stat_var))
	{
		if ( (argum[0][0] == '/') ||
		     (argum[0][0] == '.' && argum[0][1] == '/') ||
		     (argum[0][0] == '.' && argum[0][1] == '.'))
			return (argum[0]);
	}

	path_val = get_env_value("PATH", env);
	pathEnv = env_split(path_val, argum[0], fileName);

	return (pathEnv);
}
