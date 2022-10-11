#include "sort.h"
/**
 * cocktail_sort_list - sort a doubly linked list using
 * cocktrail sort
 * @list: double pointer to list to be sorted
 */
void cocktail_sort_list(listint_t **list)
{
	listint_t *i = NULL, *j = NULL, *correct = NULL, *temp = NULL;


	i = *list;

	while (i != NULL)
	{
		j = *list;
		correct = i->prev;
		while (j->next != NULL)
		{
			if ((j->n) > (j->next)->n)
			{
				temp = j->next;
				j->next = temp->next;
				if (temp->next != NULL)
					(temp->next)->prev = j;
				temp->prev = j->prev;
				if (j->prev != NULL)
					(j->prev)->next = temp;
				else
					*list = temp;
				temp->next = j;
				j->prev = temp;
				if (i->prev != correct)
					i = correct;
				j = j->prev;
			}
			j = j->next;
		}



		print_list(*list);
		i = i->next;
	}
}
