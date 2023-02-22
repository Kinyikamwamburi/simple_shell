#include "simple_shell.h"
/**
 * _strcat - concatenates two strings.
 * @dest: string 1
 * @src: string 2
 *
 * Return: return string cocatenated
 */
char *_strcat(char *dest, char *src)
{
	int lengthDest, lengthSrc, iDest, jSrc;

	lengthDest = lengthArray(dest);
	lengthSrc = lengthArray(src);
	iDest = lengthDest;
	jSrc = 0;

	for (iDest = iDest; iDest < (lengthDest + lengthSrc); iDest++)
	{
		dest[iDest] = src[jSrc];

		if ((iDest + 1) == (lengthDest + lengthSrc))
		{
			dest[iDest + 1] = '\0';
		}

		jSrc++;
	}

	return (dest);
}
/**
 * lengthArray - length array
 * @array: array
 *
 * Return: return string cocatenated
 */
int lengthArray(char *array)
{
	int length = 0;

	while (array[length] != '\0')
	{
		length++;
	}

	return (length);
}
