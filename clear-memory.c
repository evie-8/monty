#include "monty.h"
/**
 * free_stack - free memory of double linked list
 * @head: contains address of first node
 */
void free_stack(stack_t *head)
{
	stack_t *tmp;

	tmp = head;
	if (head == NULL)
		return;
	while (head != NULL)
	{
		head = head->next;
		free(tmp);
		tmp = head;
	}
}
