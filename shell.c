#include "main.h"
/**
 * main - A function that run shell commands
 * @ac: number on input arguments
 * @av: array of strings that contains arguements
 * Return: 0 on success
 */
int main(int ac, char **av, char **env)
{
		char *buffer = NULL;
		size_t size_buf = 0;
		int byte_readed = 0,  status;
		pid_t pid;
		int i = 0;
		while (1)
		{
				if (isatty(STDIN_FILENO))
						write(1, "HELL_SHELL>> ", 13);
				byte_readed = getline(&buffer, &size_buf, stdin);
				if (byte_readed == EOF)
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
				else if (*buffer == '\n')
						free(buffer);
				else
				{
						buffer[strlen(buffer) - 1] = '\0';
						char **tokens = split_buffer(buffer);
						free(buffer);
						pid = fork();
						if (pid == 0)
						{
								if (execve(tokens[0], tokens, env) == -1)
								{
										printf("%s: No such file or directory\n", av[0]);
										exit(EXIT_FAILURE);
								}
						}
						else
								wait(&status);
						i = 0;
						free(tokens);
				}
		}
		return (0);
}
