#include "monty.h"
/**
 * frees - free memory
 * @argv: to be freed
 */

void frees(char **argv)
{
	int i = 0;

	if (argv == NULL)
		return;
	while (argv[i] != NULL)
	{
		free(argv[i]);
		i++;
	}
	free(argv);
}
