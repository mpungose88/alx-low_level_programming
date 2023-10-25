#include <stdio.h>
#include <stdlib.h>
#include "lists.h"

/**
 * insert_nodeint_at_index - Inserts a new node at given position in the list.
 * @head: A pointer to the pointer of the head of the list.
 * @idx: The index where the new node should be added (starting at 0).
 * @n: The integer value to be stored in the new node.
 * Return: The address of the new node, or NULL if it failed.
 */
listint_t *insert_nodeint_at_index(listint_t **head, unsigned int idx, int n)
{
	listint_t *new_node, *current;
	unsigned int i = 0;

	if (head == NULL)
		return (NULL);
	if (idx == 0)
	{
		return (add_nodeint(head, n));
	}
	current = *head;
	while (current != NULL)
	{
		if (i == idx - 1)
		{
		new_node = malloc(sizeof(listint_t));
		if (new_node == NULL)
			return (NULL);
		new_node->n = n;
		new_node->next = current->next;
		current->next = new_node;
		return (new_node);
		}
		current = current->next;
		i++;
	}
	return (NULL);
}
