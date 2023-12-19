#include "sort.h"

/**
  *node_swap - this function swaps the node in a linked-list
  *@i: The address of first node
  *@j: The address of second node
  *Return: void
  */

void node_swap(listint_t *i, listint_t *j)
{
	if (i->prev)
		i->prev->next = j;
	if (j->next)
		j->next->prev = i;
	i->next = j->next;
	j->prev = i->prev;
	i->prev = j;
	j->next = i;
}

/**
  *insertion_sort_list - this function sorts a doubly-linked list
  *with insertion algorithm
  *@list: The address of pointer to head node
  */

void insertion_sort_list(listint_t **list)
{
	listint_t *a;
	listint_t *b;

	if (!list || !*list || !(*list)->next)
		return;
	a = (*list)->next;
	while (a)
	{
		b = a;
		a = a->next;
		while (b && b->prev)
		{
			if (b->prev->n > b->n)
			{
				node_swap(b->prev, b);
				if (!b->prev)
					*list = b;
				print_list((const listint_t *)*list);
			}
			else
				b = b->prev;
		}
	}
}
