#include "sort.h"

/**
 * swap_node - function for swapping nodes
 * @list: the head node
 * @insert: the prev node after the iter
 * @iter: the current node pointer
 */
void swap_node(listint_t **list, listint_t **insert, listint_t *iter)
{
	(*insert)->next = iter->next;
	if (iter->next != NULL)
	{
		iter->next->prev = (*insert);
	}

	iter->next = (*insert);
	iter->prev = (*insert)->prev;
	if (iter->prev != NULL)
	{
		iter->prev->next = iter;
	}
	else
	{
		(*list) = iter;
	}
	(*insert)->prev = iter;
	iter->next = (*insert);
	*insert = iter->prev;
}
/**
 * insertion_sort_list - the function to sort and a double linkedlist
 * @list: the list to be sorted
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *iter, *insert, *tmp;

	if (list == NULL || (*list) == NULL ||  (*list)->next == NULL)
	{
		return;
	}

	for (iter = (*list)->next; iter != NULL; iter = tmp)
	{
		tmp = iter->next;
		insert = iter->prev;

		while (insert != NULL && iter->n < insert->n)
		{
			swap_node(list, &insert, iter);
			print_list((const listint_t *) *list);
		}
	}
}
