#include "main.h"

/**
 * execute - execution of the command.
 * @buffer:  pointer to a string.
 * @env: double pointer to an array of env.
 */

void execute(char *buffer, char **env)
{
	char **tokens = NULL;
	char *full_path;
	pid_t pid;
	int status = 0;

	buffer[_strlen(buffer) - 1] = '\0';
	tokens = split_buffer(buffer);

	pid = fork();
	if (pid == 0)
	{
		if (stat(tokens[0], &st) == 0)
		{
			if (execve(tokens[0], tokens, env) == -1)
			{
				perror(tokens[0]);
				free_exit(tokens);
			}
		}
		else
		{
			full_path = get_full_path(tokens[0]);
			if (full_path)
			{
				if (execve(full_path, tokens, env) == -1)
				{
					perror("Error");
					free(full_path);
					free_command(tokens);
				}
			}
			else
			printf("%s: not found\n", tokens[0]);
			exit(0);
		}
	}
	else
	wait(&status);
	free(tokens);
}
