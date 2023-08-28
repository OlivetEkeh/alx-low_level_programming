#include "main.h"
/**
 *_memcpy - copies memory area
 *@dest: memory where is stored
 *@src: source memory area
 *@n: number of bytes to copy
 *
 *Return: copied memory with n bytes changed
 */
char *_memcpy(char *dest, char *src, unsigned int n)
{
	unsigned int i;

	for (i = 0; i < n; i++)
	{
	dest[i] = src[i];
	}

	return (dest);
}
