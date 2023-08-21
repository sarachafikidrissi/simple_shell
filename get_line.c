/**
 * _Mygetline - scan the line and stores it in a buffer.
 * @commandline: A pointer to the buffer where the line is stored.
 * @lineSize: A pointer to the size of the buffer.
 * @scanner: The input stream to read from.
 *
 * Return: The number of characters readed.
 */
ssize_t _Mygetline(char **commandline, size_t *lineSize, FILE *scanner)
{
	if (commandline == NULL || lineSize == NULL)
	{
		return (-1);
	}

	size_t bufferSize = *lineSize, i = 0;
	int ch;

	if (*commandline == NULL)
	{
		*commandline = (char *)malloc(bufferSize);
		if (*commandline == NULL)
		{
			return (-1);
		}
	}
	while ((ch = fgetc(scanner)) != EOF)
	{
		(*commandline)[i++] = ch;
		if (i >= bufferSize - 1)
		{
			bufferSize *= 2;
			char *newLinePtr = (char *)realloc(*commandline, bufferSize);
			if (newLinePtr == NULL)
			{
				return (-1);
			}
			*commandline = newLinePtr;
		}
		if (ch == '\n')
		{
			break;
		}
	}
	(*commandline)[i] = '\0';
	if (i == 0 && ch == EOF)
	{
		return (-1);
	}
	else
	{
		return (i);
	}
}
