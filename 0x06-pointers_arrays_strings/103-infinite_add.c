#include "main.h"

/**
 * infinite_add - Adds two numbers.
 * @n1: The first number as a string.
 * @n2: The second number as a string.
 * @r: The buffer to store the result.
 * @size_r: The size of the buffer.
 *
 * Return: A pointer to the result or 0 if the result cannot be stored in r.
 */
char *infinite_add(char *n1, char *n2, char *r, int size_r)
{
	int len1 = 0, len2 = 0, carry = 0, sum, i, j;

	while (n1[len1] != '\0')
		len1++;
	while (n2[len2] != '\0')
		len2++;

	if (len1 > size_r || len2 > size_r)
	return (0);

	r[size_r] = '\0';
	len1--, len2--, size_r--;

	for (i = len1, j = len2; i >= 0 || j >= 0 || carry > 0; i--, j--)
	{
	sum = carry;

	if (i >= 0)
		sum += n1[i] - '0';
	if (j >= 0)
		sum += n2[j] - '0';

	carry = sum / 10;
	r[size_r] = (sum % 10) + '0';
	size_r--;
	}

	if (size_r < 0)
	return (0);

	return (r + size_r + 1);
}
