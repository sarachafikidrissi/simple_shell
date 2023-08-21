#include "main.h"
/**
 * split_buffer - A function that Splits a buffer into tokens.
 * @buffer: buffer to be split.
 *
 * Return: double pointer to an array of tokens or NULL
 */
char **split_buffer(char *buffer)
{
	char *token, **tokens = NULL;
	int i = 0;

	tokens = malloc(sizeof(char *) * 1024);
	if (tokens == NULL)
		return (NULL);
	token = strtok(buffer, " \t\n");
	while (token != NULL)
	{
		tokens[i] = token;
		token = strtok(NULL, " \t\n");
		i++;
	}
	tokens[i] = NULL;
	return (tokens);
}
