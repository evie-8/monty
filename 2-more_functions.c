#include "monty.h"
/**
 * addition - adds  top 2 elements in stack
 * @stack: pointer
 * @line_number: line number
 */
void addition(stack_t **stack, unsigned int line_number)
{
	int sum;

	if (*stack == NULL || (*stack)->next == NULL)
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

/**
 * subtraction - subtracts top 2 elements in stack
 * @stack: pointer
 * @line_number: line number
 */
void subtraction(stack_t **stack, unsigned int line_number)
{
	int sum;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%u: can't sub, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	else
	{
		sum  = (*stack)->next->n - (*stack)->n;
		(*stack)->next->n = sum;
		stack_pop(stack, line_number);
	}
}

/**
 * division - divides top 2 elements in stack
 * @stack: pointer
 * @line_number: line number
 */
void division(stack_t **stack, unsigned int line_number)
{
	int sum;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%u: can't div, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	else if ((*stack)->n == 0)
	{
		fprintf(stderr, "L%u: division by zero\n", line_number);
		exit(EXIT_FAILURE);
	}
	else
	{
		sum  = (*stack)->next->n / (*stack)->n;
		(*stack)->next->n = sum;
		stack_pop(stack, line_number);
	}
}

/**
 * mult - multiplies  top 2 elements in stack
 * @stack: pointer
 * @line_number: line number
 */
void mult(stack_t **stack, unsigned int line_number)
{
	int sum;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%u: can't mul, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	else
	{
		sum  = (*stack)->next->n * (*stack)->n;
		(*stack)->next->n = sum;
		stack_pop(stack, line_number);
	}
}

/**
 * modulus - remainder top 2 elements in stack
 * @stack: pointer
 * @line_number: line number
 */
void modulus(stack_t **stack, unsigned int line_number)
{
	int sum;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%u: can't mod, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	else if ((*stack)->n == 0)
	{
		fprintf(stderr, "L%u: division by zero\n", line_number);
		exit(EXIT_FAILURE);
	}
	else
	{
		sum  = (*stack)->next->n % (*stack)->n;
		(*stack)->next->n = sum;
		stack_pop(stack, line_number);
	}
}
