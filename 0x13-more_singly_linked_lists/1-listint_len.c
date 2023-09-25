#include <stdio.h>
#include "lists.h"

/**
 * listint_len - Counts the number elements of the linked listint_t list.
 * @h: Pointer to the head of the list.
 *
 * Return: The number of elements in the list.
 */

size_t listint_len(const listint_t *h)
{
	size_t counter = 0;

	while (h != NULL)
	{
	counter++;
	h = h->next;
	}

	return (counter);
}
