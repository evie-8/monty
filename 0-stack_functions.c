#include "monty.h"
/**
 * stack_push - add item at top of stack
 * @stack: contains address of top most item in stack
 * @token: int
 * @line_number: line number
 * Return: success or failure
 */
int stack_push(char *token, stack_t **stack, unsigned int line_number)
{
	stack_t *linked;

	if (_is_digit(token) == 0 || token == NULL)
	{
		fprintf(stderr, "L%u: usage: push integer\n", line_number);
		return (EXIT_FAILURE);
	}
	linked = malloc(sizeof(stack_t));
	if (linked == NULL)
		return (mem_error());
	linked->n = atoi(token);
	linked->next = NULL;
	linked->prev = NULL;
	if (*stack == NULL)
		*stack = linked;
	else
	{
		linked->next = *stack;
		(*stack)->prev = linked;
		(*stack) = linked;
	}
	return (EXIT_SUCCESS);
}

/**
 * pall - prints elments in stack
 * @stack: pointer
 * @line_number: line number
 */
void pall(stack_t **stack, unsigned int line_number)
{
	stack_t *ptr;
	(void)line_number;

	ptr = *stack;
	while (ptr != NULL)
	{
		printf("%d\n", ptr->n);
		ptr = ptr->next;
	}
}

/**
 * pint - prints top elment in stack
 * @stack: pointer
 * @line_number: line number
 */
void pint(stack_t **stack, unsigned int line_number)
{
	(void)line_number;

	if (*stack == NULL || stack == NULL)
		return;
	printf("%d\n", (*stack)->n);
}

/**
 * stack_pop - deletes top element in stack
 * @stack: pointer
 * @line_number: line number
 */
void stack_pop(stack_t **stack, unsigned int line_number)
{
	stack_t *ptr;

	if (*stack == NULL || stack == NULL)
	{
		fprintf(stderr, "L%u: can't pop an empty stack\n", line_number);
		exit(EXIT_FAILURE);
	}
	ptr = *stack;
	*stack = (*stack)->next;
	free(ptr);
}

/**
 * swap - swap  top 2 elements in stack
 * @stack: pointer
 * @line_number: line number
 */
void swap(stack_t **stack, unsigned int line_number)
{
	stack_t *ptr;
	ssize_t len = stack_len(*stack);

	if (len < 2)
	{
		fprintf(stderr, "L%u: can't swap, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	else
	{
		ptr = (*stack)->next;
		(*stack)->next = ptr->next;
		ptr->next = *stack;
		*stack = ptr;
		ptr = (*stack)->next->prev;
		(*stack)->next->prev = *stack;
		(*stack)->prev = ptr;
	}
}
