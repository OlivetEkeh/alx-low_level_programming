#include "lists.h"

/**
 * free_listint_safe - Frees a listint_t linked list safely.
 * @h: A pointer to the pointer of the head node.
 *
 * Return: The size of the list that was freed.
 */
size_t free_listint_safe(listint_t **h)
{
	listint_t *current = *h;
	listint_t *next;
	size_t counter = 0;

	while (current != NULL)
	{
		counter++;
		next = current->next;
		free(current);
		current = next;

		if (current == *h)
		{
			*h = NULL;
			break;
		}
	}

	return (counter);
}
