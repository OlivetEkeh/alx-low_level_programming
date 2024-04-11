#include "search_algos.h"
#include <math.h>

/**
 * jump_search - searches for a value in an array of integers
 * using the Jump search algorithm
 * @array: a pointer to the first element of the array to search in
 * @size: the number of elements in array
 * @value: the value to search for
 * Return: first index where value is located
 * If value is not present in array or if array is NULL,
 * your function must return -1
 */
int jump_search(int *array, size_t size, int value)
{
	size_t i, j, block = sqrt(size), next;

	for (i = 0; i < size; i += block)
	{
		next = i + block;
		printf("Value checked array[%ld] = [%d]\n", i, array[i]);
		if (next >= size)
			next = size - 1;
		if (array[next] >= value)
		{
			printf("Value found between indexes [%ld] and [%ld]\n", i, next);
			for (j = i; j <= next; j++)
			{
				printf("Value checked array[%ld] = [%d]\n", j, array[j]);
				if (array[j] == value)
					return (j);
			}
			break;
		}
	}
	return (-1);
}
