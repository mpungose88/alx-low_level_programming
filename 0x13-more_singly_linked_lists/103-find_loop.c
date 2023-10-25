#include <stddef.h>
#include <stdio.h>
#include "lists.h"

/**
 * find_listint_loop - Finds the loop in a listint_t linked list.
 * @head: A pointer to the head of the list.
 * Return: The address of the node where the loop starts, or NULL no loop.
 */
listint_t *find_listint_loop(listint_t *head)
{
	listint_t *tortoise, *hare;

	if (head == NULL || head->next == NULL)
		return (NULL);
	tortoise = head->next;
	hare = head->next->next;
	while (tortoise != hare)
	{
		if (hare == NULL || hare->next)
			return (NULL);
		tortoise = tortoise->next;
		hare = hare->next->next;
	}
	hare = head;
	while (tortoise != hare)
	{
		tortoise = tortoise->next;
		hare = hare->next;
	}
	return (hare);
}
