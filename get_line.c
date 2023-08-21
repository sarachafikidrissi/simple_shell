#include "main.h"
/**
 * _Mygetline - A function that scans a line and stores it in a buffer.
 * @commandline: A pointer to the buffer where the line is stored.
 * @lineSize: A pointer to the size of the buffer.
 * @scanner: The input stream to read from.
 * Return: The number of characters readed.
 */
ssize_t _Mygetline(char **commandline, size_t *lineSize, FILE *scanner)
{
	char *newLinePtr;
	size_t bufferSize, i = 0;
	int ch;

	if (commandline == NULL || lineSize == NULL)
		return (-1);
	bufferSize = *lineSize;
	if (bufferSize == 0)
		bufferSize = 1024;
	if (*commandline == NULL)
	{
		*commandline = (char *)malloc(bufferSize);
		if (*commandline == NULL)
			return (-1);
	}
	while ((ch = fgetc(scanner)) != EOF)
	{
		(*commandline)[i++] = ch;
		if (i >= bufferSize - 1)
		{
			bufferSize *= 2;
			newLinePtr = (char *)realloc(*commandline, bufferSize);
			if (newLinePtr == NULL)
			{
				free(*commandline);
				return (-1);
			}
			*commandline = newLinePtr;
		}
		if (ch == '\n')
			break;
	}
	(*commandline)[i] = '\0';
	if (i == 0 && ch == EOF)
	{
		free(*commandline);
		return (-1);
	}
	else
		return (i);
}
