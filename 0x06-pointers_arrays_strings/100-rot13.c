#include "main.h"

/**
 * rot13 - Encodes a string using rot13.
 * @str: The input string.
 *
 * Return: A pointer to the modified string.
 */
char *rot13(char *str)
{
	char *ptr = str;
	char alphabet[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
	char rot13_alphabet[] = "NOPQRSTUVWXYZABCDEFGHIJKLMnopqrstuvwxyzabcdefghijklm";

	int i, j;

	while (*str != '\0')
	{
	i = 0;
	while (alphabet[i] != '\0')
	{
		if (*str == alphabet[i])
		{
			*str = rot13_alphabet[i];
			break;
	}
		i++;
	}

	str++;
	}

	return (ptr);
}
