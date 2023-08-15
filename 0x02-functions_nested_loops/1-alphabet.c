#include "main.h"
/**
 * print_alphabet - this prints the alphabeth in lower case
 *
 * Return: always 0 (Success)
 */
void print_alphabet(void)
{
	char o;

	for (o = 'a' ; o <= 'z' ; o++)
	{
		_putchar(o);
	}
	_putchar('\n');
}
