#include "sort.h"

/**
 * insertion_sort_list - Sorts a doubly linked list using insertion sort
 * @list: Double pointer to the head of the doubly linked list
 *
 * Return: Nothing
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *current = *list;
	listint_t *temp;

	while (current)
	{
		while (current->prev && current->n < current->prev->n)
		{
			temp = current->prev;

			temp->next = current->next;
			current->prev = temp->prev;
			temp->prev = current;
			current->next = temp;

			if (temp->next)
				temp->next->prev = temp;
			if (current->prev)
				current->prev->next = current;
			else
				*list = current;
			print_list(*list);
		}
		if (current->next)
			current = current->next;
		else
			break;
	}
}
