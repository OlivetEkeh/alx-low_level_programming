#include <stdio.h>

/**
 * main - Prints numbers of base 16 in lower case.
 *
 * Return: Always 0 (Success)
 */
int main(void)
{
	int w;

	for (w = 48; w < 58; w++)
	{
		putchar(w);
	}
	for (w = 97; w < 103; w++)
	{
		putchar(w);
	}
	putchar('\n');
	return (0);
}
