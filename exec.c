#include "monty.h"
/**
 * execute_monty - executes monty scripts
 * @data: contains data
 * Return: success or failure
 */
int execute_monty(FILE *data)
{
	stack_t *top = NULL;
	char **av, monty[MAX];
	int end, line = 0, change;

	while (fgets(monty, MAX, data) != NULL)
	{
		line++;
		if (strlen(monty) == 1 && monty[0] == '\n')
		{
			continue;
		}
		av = toke(monty, " \n\a\t\b");
		if (strcmp(av[0], "nop") == 0 || av[0][0] == '#')
		{
			frees(av);
			continue;
		}
		else if (strcmp(av[0], "stack") == 0)
			change = 2;
		else if (strcmp(av[0], "queue") == 0)
			change = 1;
		else if (strcmp(av[0], "push") == 0 && change == 2)
			end = stack_push(av[1], &top, line);
		else if (strcmp(av[0], "push") == 0 && change == 1)
			end = q_push(av[1], &top, line);
		else
			end = run_monty(line, av, &top);
		frees(av);
		if (end == EXIT_FAILURE)
			break;
	}
	free_stack(top);
	return (end);
}
