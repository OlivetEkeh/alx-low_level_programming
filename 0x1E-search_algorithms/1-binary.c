#include "search_algos.h"

/**
 * binary_search - searches for a value in an array of integers
 * using the Binary search algorithm
 * @array: a pointer to the first element of the array to search in
 * @size: the number of elements in array
 * @value: the value to search for
 * Return: first index where value is located
 * If value is not present in array or if array is NULL,
 * your function must return -1
 */
int binary_search(int *array, size_t size, int value)
{
	size_t i;
	int mid, low = 0, high = size - 1;

	if (!array)
		return (-1);

	while (low <= high)
	{
		mid = (low + high) / 2;

		printf("Searching in array:");
		for (i = low; i < (size_t)high; i++)
			printf(" %d,", array[i]);
		printf(" %d\n", array[high]);

		if (array[mid] == value)
			return (mid);
		else if (array[mid] < value)
			low = mid + 1;
		else if (array[mid]  > value)
			high = mid - 1;
	}
	return (-1);
}
