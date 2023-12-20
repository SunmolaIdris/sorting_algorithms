#include "sort.h"
void swap_nodes(listint_t **a, listint_t **b);
/**
 * insertion_sort_list - sorts list in ascending order
 * @list: head of list to sort
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *temp = NULL, *current = NULL, *prev = NULL;

	if (list && *list && (*list)->next)
	{
		temp = (*list)->next;

		while (temp) /* iterate to end of list */
		{
			current = temp;
			prev = temp->prev;

			/* if values are not ascending */
			while (prev && current->n < prev->n)
			{
				swap_nodes(&prev, &current);
				if (prev == *list) /* if current now list head */
					*list = current;
				print_list(*list);
				/* if (current->prev != NULL) if not at head of list */
				prev = current->prev;
			}
			temp = temp->next;
		}
	}
}
/**
 * swap_nodes - swap two nodes
 * @a: left node
 * @b: right node
 */
void swap_nodes(listint_t **a, listint_t **b)
{
	(*a)->next = (*b)->next;
	(*b)->prev = (*a)->prev;
	if ((*b)->next)
		(*b)->next->prev = (*a);
	if ((*a)->prev)
		(*a)->prev->next = (*b);
	(*b)->next = (*a);
	(*a)->prev = (*b);
}
