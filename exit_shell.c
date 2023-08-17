#include "main.h"
/**
 * exit_shell - a function that exits the shell
 * @tokens: an array of strings
 * Return: Nothing
*/
void exit_shell(char **tokens)
{
	int status = 0;

	if (tokens[1] == NULL)
	{
		free_command(tokens);
		exit(EXIT_SUCCESS);
	}

	status = atoi(tokens[1]);

	free_command(tokens);
	exit(status);
}
