#include "simple_shell.h"

/**
* read_textfile - read file
* d_textfile - read file
* and print with API POSIX standard output.
* @filename: string
* @letters: number of characters for read and print
* Return: number of characters printed
*/
ssize_t read_textfile(const char *filename, size_t letters)
{

	int fileD, bL, bW;
	char *text;

	if (!filename)
		return (0);
	text = malloc(sizeof(char) * letters);
	if (!text)
		return (0);
	fileD = open(filename, O_RDWR);
	if (fileD == -1)
	{
		free(text);
		return (0);
	}
	bL = read(fileD, text, letters);
	if (bL == -1)
		return (0);
	bW = write(STDOUT_FILENO, text, bL);
	if (bW < 0)
		return (0);
	free(text);
	close(fileD);
	return (bW);
}
