#include "main.h"

/**
 * print_alphabet_x10 - this prints the alphabeth x10 in lower case
 *
 * Return: always 0 (Success)
 *
 */

void print_alphabet_x10(void)
{
	char o;
	int i;
	i = 0;

	while (i < 10)
	{
		for (o = 'a' ; o <= 'z' ; o++)
		{
			_putchar(o);
		}
		_putchar('\n');
		i++;
	}
}
