#include "main.h"

/**
 * print rev - print a string in reverse
 *
 * @s: the string input to be reverse
 *
 */
void print_rev(char *s)
{
	int l = 0;

	while (s[l] != '\0')
	{
		l++;
	}

	for (l-- ; l >= 0; l--)
	_putchar(s[l]);

	_putchar('\n');
}
