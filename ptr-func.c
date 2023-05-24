#include "monty.h"
/**
 * run_monty - run functions
 * @argv: array
 * @stack: pointer
 * @line_number: line number
 * Return: success or failure
 */
int run_monty(unsigned int line_number, char **argv, stack_t **stack)
{
	int i;
	instruction_t operation[] = {{"pall", pall}, {"pint", pint},
		{"pop", stack_pop}, {"swap", swap}, {"add", addition},
		{NULL, NULL}};

	for (i = 0; operation[i].opcode != NULL; i++)
	{
		if (strcmp(operation[i].opcode, argv[0]) == 0)
		{
			operation[i].f(stack, line_number);
			return (EXIT_SUCCESS);
		}
	}
	free_stack(*stack);
	opcode_error(line_number, argv[0]);
	return (EXIT_SUCCESS);
}
