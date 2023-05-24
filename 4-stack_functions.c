#include "monty.h"
/**
 *print_char - checks if its a character
 * @stack: pointer
 * @line_number: line number
 */
void print_char(stack_t **stack, unsigned int line_number)
{
	if (*stack == NULL)
	{
		fprintf(stderr, "L%u: can't pchar, stack empty\n", line_number);
		exit(EXIT_FAILURE);
	}
	if ((*stack)->n >= 0 && (*stack)->n < 128)
		printf("%c\n", (*stack)->n);
	else
	{
		fprintf(stderr, "L%u: can't pchar, value out of range\n", line_number);
		exit(EXIT_FAILURE);
	}
}

/**
 *print_str - checks if its a character
 * @stack: pointer
 * @line_number: line number
 */
void print_str(stack_t **stack, unsigned int line_number)
{
	stack_t *ptr;
	(void)line_number;

	ptr = *stack;
	if (*stack == NULL || stack == NULL)
	{
		printf("\n");
		return;
	}
	while (ptr != NULL && (ptr->n > 0 && ptr->n < 128))
	{
		printf("%c", ptr->n);
		ptr = ptr->next;
	}
	printf("\n");
}

/**
 * rotate1 - top become last and secon becomes first
 * @stack: pointer
 * @line_number: line number
 */
void rotate1(stack_t **stack, unsigned int line_number)
{
	stack_t *new, *ptr;
	(void)line_number;

	if (*stack == NULL)
		return;
	if ((*stack)->next == NULL)
		return;
	ptr = *stack;
	new = (*stack)->next;
	while (ptr->next != NULL)
		ptr = ptr->next;
	ptr->next = *stack;
	ptr->next->next = NULL;
	ptr->next->prev = ptr;
	new->prev = NULL;
	*stack = new;
}

/**
 * rotate2 - last become top
 * @stack: pointer
 * @line_number: line number
 */
void rotate2(stack_t **stack, unsigned int line_number)
{
	stack_t *ptr;
	(void)line_number;

	if (*stack == NULL)
		return;
	if ((*stack)->next == NULL)
		return;
	ptr = *stack;
	while (ptr->next != NULL)
		ptr = ptr->next;
	ptr->prev->next = NULL;
	ptr->next = *stack;
	(*stack)->prev = ptr;
	ptr->prev = NULL;
	*stack = ptr;
}
