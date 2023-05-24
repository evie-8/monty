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
/**
 * q_push - add item at botton of stack
 * @stack: contains address of top most item in stack
 * @token: int
 * @line_number: line number
 * Return: success or failure
 */
int q_push(char *token, stack_t **stack, unsigned int line_number)
{
	stack_t *linked, *ptr;

	if (token == NULL)
	{
		fprintf(stderr, "L%u: usage: push integer\n", line_number);
		exit(EXIT_FAILURE);
	}
	if (_is_digit(token) == 0)
	{
		fprintf(stderr, "L%u: usage: push integer\n", line_number);
		exit(EXIT_FAILURE);
	}
	linked = malloc(sizeof(stack_t));
	if (linked == NULL)
		mem_error();
	linked->n = atoi(token);
	linked->next = NULL;
	linked->prev = NULL;
	if (*stack == NULL || stack == NULL)
		*stack = linked;
	else
	{
		ptr = *stack;
		while (ptr->next != NULL)
			ptr = ptr->next;
		ptr->next = linked;
		linked->prev = ptr;
		/* (*stack) = linked; */
	}
	return (EXIT_SUCCESS);
}
