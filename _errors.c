#include "simple_shell.h"
/**
 * showError - display de errors
 * @arg: arguments
 * @fileName: executable file name
 *
 * Return: nothing
 */
void showError(char **arg, char *fileName)
{
	int cntArg = countArguments(arg);

	write(STDERR_FILENO, fileName, lengthArray(fileName));
	write(STDERR_FILENO, ": ", 2);
	_print_numbers_recursion(cntArg);
	write(STDERR_FILENO, ": ", 2);
	write(STDERR_FILENO, arg[0], lengthArray(arg[0]));
	write(STDERR_FILENO, ": ", 2);
	write(STDERR_FILENO, "not found\n", 10);

	exit(127);
}
/**
 * countArguments - count the arguments send
 * @arg: arguments
 *
 * Return: counter
 */
int countArguments(char **arg)
{
	int cnt = 0;

	while (arg[cnt] != NULL)
		cnt++;

	return (cnt);
}
