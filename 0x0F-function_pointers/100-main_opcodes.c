#include <stdio.h>
#include <stdlib.h>

/**
 * main - prints its own opcodes
 * @argc: number of arguments
 * @argv: array of arguments
 *
 * Return: Always 0 (Success)
 */
int main(int argc, char *argv[])
{
	int bytes;
	int i;
	char *arr;

	if (argc != 2)
	{
		fprintf(stderr, "Usage: %s <number_of_bytes>\n", argv[0]);
		exit(EXIT_FAILURE);
	}

	bytes = atoi(argv[1]);

	if (bytes <= 0)
	{
		fprintf(stderr, "Error: .\n");
		exit(EXIT_FAILURE);
	}

	arr = (char *)main;

	for (i = 0; i < bytes; i++)
	{
		if (i == bytes - 1)
		{
			printf("%02hhx\n", arr[i]);
		}
		else
		{
			printf("%02hhx ", arr[i]);
		}
	}

	return (0);
}
