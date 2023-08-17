#include "main.h"

/**
 * get_env - a function that returns the environement
 * @str: the path lokking for
 * Return: value of path, NULL if doesn't exist
*/
char *get_env(char *str)
{
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
