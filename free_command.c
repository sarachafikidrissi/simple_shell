#include "main.h"

/**
 * free_command - Frees memory allocated for an array of tokens.
 * @tokens: Double pointer to an array of tokens.
 */
void free_command(char **tokens)
{
	size_t i = 0;

	if (tokens == NULL)
		return;
	while (tokens[i])
	{
		free(tokens[i]);
		i++;
	}
	if (tokens[i] == NULL)
		free(tokens[i]);

	free(tokens);
}
