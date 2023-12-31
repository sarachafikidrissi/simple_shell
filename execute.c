#include "main.h"
/**
 * execute - execution of the command.
 * @buffer:  pointer to a string.
 * @env: double pointer to an array of env.
 */
void execute(char *buffer, char **env)
{
	struct stat st;
	char **tokens = NULL, *full_path;
	int status = 0, pid;

	buffer[_strlen(buffer) - 1] = '\0';
	tokens = split_buffer(buffer);
	if (_strcmp(tokens[0], "exit") != 0)
		exit_shell(tokens);
	else if (_strcmp(tokens[0], "env") != 0)
		print_env(env);
	pid = fork();
	if (pid == 0)
	{
		if (stat(tokens[0], &st) == 0)
		{
			if (execve(tokens[0], tokens, env) == -1)
			{perror(tokens[0]);
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
