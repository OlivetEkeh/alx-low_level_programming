#include <stdio.h>
#include "function_pointers.h"

/**
 * int_index - searches for an integer in an array
 * @array: array of integers
 * @size: number of elements in the array
 * @cmp: pointer to the comparison function
 *
 * Return:  element for which cmp doesn't return 0, or -1 if no match.
 */
int int_index(int *array, int size, int (*cmp)(int))
{
	if (array != NULL && cmp != NULL && size > 0)
	{
		int i;

		for (i = 0; i < size; i++)
		{
			if (cmp(array[i]) != 0)
				return (i);
		}
	}
	return (-1);
}
