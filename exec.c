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
	int i = 0, end, t, line = 0;

	av = tokenize(data, "\n");
	t = sizes(av);
	while (i < t)
	{
		line++;
		if (strlen(av[i]) == 0)
		{
			i++;
			continue;
		}
		monty = toke(av[i], " \n\a\t\b\r");
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
/**
 * sizes - size of two dimensional array
 *@array: array
 * Return: size
 */
int sizes(char **array)
{
	int i = 0;

	while (array[i])
		i++;
	return (i);
}

