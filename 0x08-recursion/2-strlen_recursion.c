#include <stdio.h>

/**
 * _strlen_recursion - Returns the leanth of a string.
 * @s: The string to find the length.
 *
 * Return: The lenght of the string.
 */
int _strlen_recursion(char *s)
{
	if (*s == '\0')
	{
		return (0);
	}

	return (1 + _strlen_recursion(s + 1));
}
