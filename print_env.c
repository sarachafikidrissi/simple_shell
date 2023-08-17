#include "main.h"
/**
 * print_env - Prints an array of environment variables.
 * @env: Double pointer to the array of environment variables.
 */

void print_env(char **env)
{
	int i = 0;

	while (env[i])
	{
		printf("%s\n", env[i]);
		i++;
	}
}
