
#include "simple_shell.h"
/**
 * ctrlcValidate - validate the ctrl c
 *
 * Return: is a void
 */
void ctrlcValidate(void)
{
	signal(SIGINT, newPrompt);
}
/**
 * newPrompt - printf a new line in the prompt
 * @_signal: signal data
 *
 * Return: cnt.
 */
void newPrompt(int _signal)
{
	(void)_signal;
	_putchar('\n');
	_putchar('$');
}
