#include "sort.h"

/**
 * insertion_sort_list - sorts a doubly linked list using
 * the insertion sort algorithm
 * @list: double pointer to head of the list
 */
void insertion_sort_list(listint_t **list)
{

	listint_t *i = NULL;
	listint_t *hold = NULL;
	listint_t *key = NULL;
	listint_t *j = NULL;

	if (*list == NULL)
		return;


	i = (*list)->next;

	while (i != NULL)
	{
		key = i;
		i = i->next;
		j = key->prev;
		hold = key->next;

		while (j != NULL && (j->n) > (key->n))
		{
			j->next = hold;
			if (hold)
				(hold)->prev = j;
			hold = j;
			j = j->prev;
			print_list(*list);
		}
		key->prev = j;
		if (j)
			j->next = key;
		else
			*list = key;

		key->next = hold;
		if (hold)
			hold->prev = key;


	}
}
