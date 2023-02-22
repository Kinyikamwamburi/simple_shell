#include "simple_shell.h"
/**
 * copyEnv - create a copy from env
 * @env: enviroments variables
 *
 * Return: return **pointer
 */
char **copyEnv(char **env)
{
	int cntArg = countArguments(env);
	int cnt = 0, cntDinamyc;
	char **cpyEnv = malloc(sizeof(char *) * cntArg);

	if (cpyEnv == NULL)
		perror("Error");

	while (env[cnt] != NULL)
	{
		cntDinamyc = lengthArray(env[cnt]);
		cpyEnv[cnt] = malloc(sizeof(char) * cntDinamyc);

		if (cpyEnv[cnt] == NULL)
		{
			cnt--;
			while (cnt >= 0)
			{
				free(cpyEnv[cnt]);
			}
			free(cpyEnv);
			perror("Error");
		}


		_strcpy(cpyEnv[cnt], env[cnt]);
		cnt++;
	}

	return (cpyEnv);
}
/**
 * freeDoubleArray - free a **pointer
 * @arg: pointer to free
 *
 * Return: is a void
 */
void freeDoubleArray(char **arg)
{
	int cnt = countArguments(arg);

	cnt--;

	while (cnt >= 0)
	{
		free(arg[cnt]);
		cnt--;
	}

	free(arg);
}
