#include "main.h"
/**
 * _strlen - A function that calculates the length of a string
 * @s: The input string
 * Return: length of the string
 */
unsigned int _strlen(char *s)
{
	unsigned int len = 0;

	while (s[len])
		len++;

	return (len);
}
