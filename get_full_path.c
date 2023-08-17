#include "main.h"
/**
 * get_full_path - a fuction that returns the full path of a command
 * @input: the user input
 * Return: full path of input, NULL if doesn't exist
*/
char *get_full_path(char *input)
{
		char *full_path;
		char *token;
		struct stat st;

		char *path = get_env("PATH");

		token = strtok(path, ":");

		while (token)
		{
			full_path = malloc(strlen(input) + strlen(path) + 2);
			strcpy(full_path, token);
			strcat(full_path, "/");
			strcat(full_path, input);
			if (stat(full_path, &st) == 0)
				return (full_path);
			free(full_path);
			token = strtok(NULL, ":");
		}
		return (NULL);
}
