#include "sort.h"
void f_bubble(listint_t **list, listint_t *j, listint_t *i, listint_t *crt);
void b_bubble(listint_t **list, listint_t *j, listint_t *i, listint_t *crt_b);
/**
 * cocktail_sort_list - sort a doubly linked list using
 * cocktrail sort
 * @list: double pointer to list to be sorted
 */
void cocktail_sort_list(listint_t **list)
{
	listint_t *i = NULL, *j = NULL, *crt = NULL;
	listint_t *crt_b = NULL;

	i = *list;

	while (i != NULL)
	{
		j = *list;
		crt = i->prev;
		crt_b = i->next;

		f_bubble(list, j, i, crt);

		b_bubble(list, j, i, crt_b);
		i = i->next;
	}
}

/**
 * f_bubble - performs bubble sort in the forword direction
 * @list: pointer to the list
 * @j: one of the aux pointer
 * @i: keeps track of itteration
 * @crt: controls when to adjust head pointer
 */
void f_bubble(listint_t **list, listint_t *j, listint_t *i, listint_t *crt)
{
	listint_t *temp = NULL;

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
			if (i->prev != crt)
				i = crt;
			j = j->prev;
			print_list(*list);
		}
		j = j->next;
	}
}

/**
 * b_bubble - performs bubble sort in the forword direction
 * @list: pointer to the list
 * @j: one of the aux pointer
 * @i: keeps track of itteration
 * @crt_b: controls when to adjust head pointer
 */
void b_bubble(listint_t **list, listint_t *j, listint_t *i, listint_t *crt_b)
{
	listint_t *temp = NULL;

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
			if (i->next != crt_b)
				i = crt_b;
			j = j->next;
			print_list(*list);
		}
		j = j->prev;
	}
}
