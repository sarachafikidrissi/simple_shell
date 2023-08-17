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
		char *buffer = NULL, **tokens = NULL;
		char *full_path;
		size_t size_buf = 0;
		int byte_readed = 0,  status;
		pid_t pid;
		(void)ac;
		struct stat st;

		while (1)
		{
			if (isatty(STDIN_FILENO))
				write(1, "HELL_SHELL>> ", 13);
			byte_readed = getline(&buffer, &size_buf, stdin);
			if (byte_readed == EOF)
				handle_EOF(buffer);
			else if (*buffer == '\n')
				free(buffer);
			else
			{
				buffer[strlen(buffer) - 1] = '\0';
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
			free(buffer);
			buffer = NULL;
		}
		return (0);
}
