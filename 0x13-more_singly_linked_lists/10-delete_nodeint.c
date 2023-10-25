#include <stdlib.h>
#include <stdio.h>
#include "lists.h"

/**
 * delete_nodeint_at_index - Deletes a node at a specified index in the list.
 * @head: A pointer to the pointer of the head of the list.
 * @index: The index of the node to be deleted (starting at 0).
 * Return: 1 if it succeeded, -1 if it failed.
 */
int delete_nodeint_at_index(listint_t **head, unsigned int index)
{
	listint_t *current, *temp;
	unsigned int i = 0;

	if (head == NULL || *head == NULL)
		return (-1);
	if (index == 0)
	{
		temp = *head;
		*head = temp->next;
		free(temp);
		return (1);
	}
	current = *head;
	while (current != NULL)
	{
		if (i == index - 1)
		{
			if (current->next != NULL)
		{
			temp = current->next;
			current->next = temp->next;
			free(temp);
			return (1);
		}
			else
				return (-1);
		}
		current = current->next;
		i++;
	}
	return (-1);
}
