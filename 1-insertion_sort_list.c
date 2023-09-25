#include "sort.h"

/**
 * insertion_sort - insertion sort algorithm
 * @list: the list to be sorted
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *tmp, *tmp2, *temp;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;
	tmp = *list;
	while (tmp->next != NULL)
	{
		tmp2 = tmp->next;
		while (tmp2 != NULL && tmp2->n < tmp2->prev->n)
		{
			temp = tmp2->prev;
			temp->next = tmp2->next;

			if (tmp2->next != NULL)
				tmp2->next->prev = temp;

			tmp2->prev = temp->prev;

			temp->prev = tmp2;
			tmp2->next = temp;
		}
		tmp = tmp->next;
	}
}
