#include <stdio.h>

/**
 * main - Entry point
 *
 * Description: This is the main function that prints the name of the file
 * it was compiled from.
 *
 * Return: Always 0 (Success)
 */

int main(void)
{
	printf("%s\n", __FILE__);
	return (0);
}
