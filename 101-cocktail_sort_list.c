#include "sort.h"
/**
 * cocktail_sort_list - sort a doubly linked list using
 * cocktrail sort
 * @list: double pointer to list to be sorted
 */
void cocktail_sort_list(listint_t **list)
{
	listint_t *i = NULL, *j = NULL, *correct = NULL, *temp = NULL;
	listint_t *correct_b = NULL;

	i = *list;

	while (i != NULL)
	{
		j = *list;
		correct = i->prev;
		correct_b = i->next;

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
				print_list(*list);
			}
			j = j->next;
		}

                while (j->prev != NULL)
                {
                        if ((j->n) < (j->prev)->n)
                        {
                                temp = j->prev;
                                j->prev = temp->prev;
                                if (temp->prev != NULL)
                                        (temp->prev)->next = j;
				else
					*list = j;
                                temp->next = j->next;
                                if (j->next != NULL)
                                        (j->next)->prev = temp;
                                temp->prev = j;
                                j->next = temp;
                                if (i->next != correct_b)
                                        i = correct_b;
                                j = j->next;
				print_list(*list);
                        }
                        j = j->prev;
                }
		i = i->next;
	}
}
