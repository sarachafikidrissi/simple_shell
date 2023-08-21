#include "main.h"
/**
 * main - A function that run shell commands
 * @ac: number on input arguments
 * @av: array of strings that contains arguements
 * @env: an array of string contains the enviroement
 * Return: 0 on success
 */
int main(int ac, char **av, char **env)
{
	char *buffer = NULL;
	size_t size_buf = 0;
	int byte_readed = 0;
	(void)ac;
	(void)av;

	while (1)
	{
		if (isatty(STDIN_FILENO))
			write(1, "HELL_SHELL>> ", 13);
		byte_readed = getline(&buffer, &size_buf, stdin);
		if (byte_readed == EOF)
			handle_EOF(buffer);
		else if (*buffer == '\n' || strspn(buffer, " \t\r\n") == strlen(buffer))
		{
			continue;
		}
		else
			execute(buffer, env);
		free(buffer);
		buffer = NULL;
	}
	return (0);
}
