#include <stdlib.h>
#include <stdio.h>
#include "lists.h"

/**
 * free_listint_safe - Frees a listint_t list safely.
 * @h: A pointer to the pointer of the head of the list.
 * Return: The size of the list that was freed.
 */
size_t free_listint_safe(listint_t **h)
{
	size_t count = 0;
	listint_t *current, *temp;

	if (h == NULL || *h == NULL)
		return (0);
	current = *h;
	while (current != NULL)
	{
		temp = current;
		current = current->next;
		free(temp);
		count++;
	}
	*h = NULL;
	return (count);
}
