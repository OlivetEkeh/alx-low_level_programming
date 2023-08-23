#include "main.h"

/**
 * cap_string - Capitalizes all words in a string.
 * @str: The input string.
 *
 * Return: A pointer to the modified string.
 */
char *cap_string(char *str)
{
	char *ptr = str;
	int capitalize_next = 1;

	while (*str != '\0')
	{
	if ((*str >= 'a' && *str <= 'z') && capitalize_next)
	{
		*str = *str - 32;
		capitalize_next = 0;
	}
	else if (*str == ' ' || *str == '\t' || *str == '\n' || *str == ',' ||
		*str == ';' || *str == '.' || *str == '!' || *str == '?' ||
		*str == '"' || *str == '(' || *str == ')' || *str == '{' ||
		*str == '}')
	{
		capitalize_next = 1;
	}
	else
	{
		capitalize_next = 0;
	}

	str++;
	}

	return (ptr);
}
