#include "main.h"

/**
 * string_toupper - Converts all lowercase letters of a string to uppercase.
 * @str: The input string.
 *
 * Return: A pointer to the modified string.
 */
char *string_toupper(char *str)
{
	char *ptr = str;

	while (*str != '\0')
	{
		if (*str >= 'a' && *str <= 'z')
		*str = *str - 32;
	str++;
	}

	return (ptr);
}
