#include <stddef.h>

/**
 * listint_len - returns the number of elements in a linked listint_t list.
 * @h: Pointer to the head of the linked list.
 * Return: The number of elements in the list.
 */
size_t listint_len(const listint_t *h)
{
	size_t count = 0;

	while (h != NULL)
	{
		count++;
		h = h->next;
	}
	return (count);
}
