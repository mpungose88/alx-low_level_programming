#include <stddef.h>
#include <stdio.h>
#include "lists.h"

/**
 * sum_listint - Returns the sum of all data (n) in a listint_t linked list.
 * @head: A pointer to the head of the list.
 * Return: The sum of all data (n) in the linked list, or 0 if list is empty.
 */
int sum_listint(listint_t *head)
{
	int sum = 0;

	while (head != NULL)
	{
		sum += head->n;
		head = head->next;
	}
	return (sum);
}
