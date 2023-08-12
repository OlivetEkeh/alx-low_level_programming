#include <stdio.h>

/**
 * main - this prints the lowercase alphabet in reverse,
 * followed by a new line
 * Return: Always 0 (Success)
 */
int main(void)
{
	char ol;

	for (ol = 'z'; ol >= 'a'; ol--)
	{
		putchar(ol);
	}
	putchar('\n');
	return (0);
}
