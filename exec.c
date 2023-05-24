#include "monty.h"
/**
 * execute_monty - executes monty scripts
 * @data: contains data
 * Return: success or failure
 */
int execute_monty(char *data)
{
	stack_t *top = NULL;
	char **av, **monty, *cpy;
	int i = 0, end;

	av = tokenize(data, "\n");
	while (av[i] != NULL)
	{
		cpy = _strdup(av[i]);
		monty = tokenize(cpy, " \n\t\r\a\t");
		if (strcmp(monty[0], "nop") == 0 || monty[0][0] == '#')
		{
			frees(monty);
			free(cpy);
			i++;
			continue;
		}
		else if (strcmp(monty[0], "push") == 0)
			end = stack_push(monty[1], &top, i + 1);
		else
			end = run_monty(i + 1, monty, &top);
		frees(monty);
		free(cpy);
		i++;
	}
	frees(av);
	return (end);
}
