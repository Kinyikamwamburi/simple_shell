#include "shell.h"

/**
  * _strlen - finds the length of a string.
  * Return: length of c.
  * @pointer: pointer.
  */
int _strlen(char *pointer)
{
	int c = 0;

	while (*(pointer + c) != '\0')
	{
		c++;
	}
	return (c);
}
