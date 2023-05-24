#include "monty.h"
/**
 * execute_monty - executes monty scripts
 * @data: contains data
 * Return: success or failure
 */
int execute_monty(char *data)
{
	stack_t *top = NULL;
	char **av, **monty;
	int i = 0, end, line = 0;

	av = tokenize(data, "\n");
	while (av[i] != NULL)
	{
		line++;
		monty = tokenize(av[i], " \n\a\t\b");
		if (_empty(av[i], " ") == 0)
			continue;
		if (strcmp(monty[0], "nop") == 0 || monty[0][0] == '#')
		{
			frees(monty);
			i++;
			continue;
		}
		else if (strcmp(monty[0], "push") == 0)
			end = stack_push(monty[1], &top, line);
		else
			end = run_monty(line, monty, &top);
		frees(monty);
		i++;
	}
	frees(av);
	return (end);
}
