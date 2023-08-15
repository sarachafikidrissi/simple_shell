#include "main.h"
/**
 * handle_EOF - a function that handles end of file
 * @buffer: the string to handle
 * Return: Nothing
 */
void handle_EOF(char *buffer)
{
	if (buffer)
	{
		free(buffer);
		buffer = NULL;
	}
	if (isatty(STDIN_FILENO))
			write(1, "\n", 1);
	free(buffer);
	exit(0);
}
