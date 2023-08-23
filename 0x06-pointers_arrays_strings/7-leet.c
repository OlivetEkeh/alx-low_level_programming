#include "main.h"

/**
 * leet - Encodes a string into 1337.
 * @str: The input string.
 *
 * Return: A pointer to the modified string.
 */
char *leet(char *str)
{
	char *ptr = str;
	char leet_letters[] = "aeotlAEOTL";
	char leet_numbers[] = "4307143071";
	int i;

	while (*str != '\0')
	{
	i = 0;
		while (leet_letters[i] != '\0')
	{
		if (*str == leet_letters[i])

		{
		*str = leet_numbers[i];
		break;
		}
		i++;
	}

		str++;
	}

	return (ptr);
}
