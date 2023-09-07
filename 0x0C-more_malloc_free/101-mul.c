#include <stdio.h>
#include <stdlib.h>
#include "main.h"

/**
 * _isdigit - Checks if a character is a digit (0-9)
 * @c: The character to check
 *
 * Return: 1 if the character is a digit, 0 otherwise
 */
int _isdigit(char c)
{
	return (c >= '0' && c <= '9');
}

/**
 * _strlen - Computes the length of a string
 * @s: The string to measure
 *
 * Return: The length of the string
 */
int _strlen(char *s)
{
	int len = 0;

	while (s[len] != '\0')
		len++;

	return (len);
}

/**
 * mul - Multiplies two positive numbers
 * @argc: The number of command-line arguments
 * @argv: An array of command-line arguments
 *
 * Return: 0 if successful, 98 if there's an error
 */
int mul(int argc, char *argv[])
{
	int i, j, len1, len2, carry, result;
	int *mul_result;
	char *num1, *num2;

	if (argc != 3)
	{
		printf("Error\n");
		return (98);
	}

	num1 = argv[1];
	num2 = argv[2];

	len1 = _strlen(num1);
	len2 = _strlen(num2);

	mul_result = malloc(sizeof(int) * (len1 + len2));

	if (mul_result == NULL)
	{
		printf("Error\n");
		return (98);
	}

	for (i = len1 - 1; i >= 0; i--)
	{
		carry = 0;
		for (j = len2 - 1; j >= 0; j--)
		{
			result = (num1[i] - '0') * (num2[j] - '0') + mul_result[i + j + 1] + carry;
			mul_result[i + j + 1] = result % 10;
			carry = result / 10;
		}
		mul_result[i + j + 1] = carry;
	}

	for (i = 0; i < len1 + len2; i++)
		printf("%d", mul_result[i]);
	printf("\n");

	free(mul_result);

	return (0);
}

/**
 * main - Entry point
 * @argc: The number of command-line arguments
 * @argv: An array of command-line arguments
 *
 * Return: 0 if successful, 98 if there's an error
 */
int main(int argc, char *argv[])
{
	return (mul(argc, argv));
}
