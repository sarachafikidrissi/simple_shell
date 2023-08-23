#include "main.h"
/**
 * execute - execution of the command.
 * @tokens: array of string
 * @buffer:  pointer to a string.
 * @env: double pointer to an array of env.
 */
void execute(char **tokens, char **env)
{
	char *full_path;
	int status = 0, pid, exit_status;

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
	{wait(&status);
		if (WIFEXITED(status))
		{exit_status = WEXITSTATUS(status);

			if (exit_status != 0)
				exit(exit_status);
		}
	}
	free(tokens);
}
