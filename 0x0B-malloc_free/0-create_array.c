#include <stdlib.h>

/**
 * create_array - creates array of chars and initializes with a specific char
 * @size: the size of the array to create
 * @c: the character to initialize the array with
 *
 * Return: If size is 0 or if memory allocation fails, returns NULL.
 * Otherwise, returns a pointer to the created array.
 */
char *create_array(unsigned int size, char c)
{
	unsigned int i;
	char *array;

	if (size == 0)
		return (NULL);

	array = malloc(size * sizeof(char));

	if (array == NULL)
		return (NULL);


	for (i = 0; i < size; i++)
		array[i] = c;

	return (array);
}
