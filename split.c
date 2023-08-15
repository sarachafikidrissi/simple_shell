#include "main.h"
/**
 * split_buffer - Splits a buffer into tokens.
 * @buffer: The buffer to be split.
 *
 * Return: A double pointer to an array of tokens.
 */
char **split_buffer(char *buffer)
{
	char *token, **tokens = NULL;
	int i = 0;

	tokens = malloc(sizeof(char *) * 1024);
	token = strtok(buffer, " \0");
	while (token != NULL)
	{
		tokens[i] = token;
		token = strtok(NULL, " \0");
		i++;
	}
	tokens[i] = NULL;
	return (tokens);
}
