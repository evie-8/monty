#include "monty.h"
/**
 * tokenize - splits string
 * @command: string to be broken
 * @delim: delimiter
 * Return: array of strings
 */
char **tokenize(char *command, char *delim)
{
	char *cmd_cpy = NULL, *token = NULL, **argv = NULL;
	int argc = 0, i;

	if (command == NULL)
		return (NULL);
	cmd_cpy = _strdup(command);
	if (cmd_cpy == NULL)
		return (NULL);
	while ((token = _strsep(&command, delim)) != NULL)
	{
		argc++;
	}
	argv = malloc(sizeof(char *) * (argc + 1));
	if (argv == NULL)
		return (NULL);
	i = 0;
	while ((token = _strsep(&cmd_cpy, delim)) != NULL)
	{
		argv[i] = _strdup(token);
		if (argv[i] == NULL)
		{
			frees(argv);
			free(cmd_cpy);
			return (NULL);
		}
		i++;
	}
	argv[argc] = NULL;
	free(cmd_cpy);
	return (argv);
}
