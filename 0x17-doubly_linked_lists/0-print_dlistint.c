#include "lists.h"

/**
 * print_dlistint - this prints the double linked list
 * @h: the first node
 * Return: the number od nodes
 */

size_t print_dlistint(const dlistint_t *h)
{
	size_t count = 0;

	while (h != NULL)
	{
		printf("%d\n", h->n);
		h = h->next;
		count++;
	}

	return (count);
}
