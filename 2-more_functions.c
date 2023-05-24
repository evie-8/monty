#include "monty.h"
/**
 * addition - adds  top 2 elements in stack
 * @stack: pointer
 * @line_number: line number
 */
void addition(stack_t **stack, unsigned int line_number)
{
	int sum;
	ssize_t len = stack_len(*stack);

	if (len < 2)
	{
		fprintf(stderr, "L%u: can't add, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	else
	{
		sum  = (*stack)->next->n + (*stack)->n;
		(*stack)->next->n = sum;
		stack_pop(stack, line_number);
	}
}
