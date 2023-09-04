#include <stdlib.h>
#include "main.h"
/**
 * argstostr - concatenates all the arguments of your program
 * @ac: number of arguments
 * @av: array of argument strings
 *
 * Return: A pointer to a new string or NULL if it fails.
 */
char *argstostr(int ac, char **av)
{
	int i, j, len = 0;
	char *str;
	int k = 0;

	if (ac == 0 || av == NULL)
		return (NULL);

	for (i = 0; i < ac; i++)
	{
	for (j = 0; av[i][j] != '\0'; j++)
	{
		len++;
	}
		len++;
	}

	str = (char *)malloc(sizeof(char) * (len + 1));

	if (str == NULL)
	return (NULL);

	for (i = 0; i < ac; i++)
	{
		for (j = 0; av[i][j] != '\0'; j++)
	{
		str[k++] = av[i][j];
	}
	str[k++] = '\n';
	}
	str[len] = '\0';

	return (str);
}
