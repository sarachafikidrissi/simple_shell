#include "main.h"

/**
 * free_exit - Frees memory and exits with failure status.
 * @tokens: Double pointer to an array of tokens.
 */
void free_exit(char **tokens)
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
	exit(EXIT_FAILURE);
}
