#include "main.h"

/**
 * get_env - a function that returns the environement
 * @ste: the path lokking for
 * Return: value of path, NULL if doesn't exist
*/
char *get_env(char *str)
{
		extern char **environ;
		int i = 0;
		char *token;

		while (environ[i])
		{
				token = strtok(environ[i], "=");

				if (strcmp(str, token) == 0)
						return (strtok(NULL, "\n"));
				i++;
		}
		return (NULL);
}
