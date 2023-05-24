#include "monty.h"
/**
 * _is_digit - checks if string has only digits
 * @s: string
 * Return: 1 if all are digits
 */
int _is_digit(char *s)
{

	int j = 0, i = 0;

	while (s[i])
		i++;
	if (s[0] == '-')
		j++;
	while (j < i)
	{
		if (s[j] >= 48 && s[j] <= 57)
		{
		}
		else
			return (0);
		j++;
	}
	return (1);

}
/**
 * stack_len - return number of nodes
 * @h: contains first node address
 * Return: length
 */
size_t stack_len(stack_t *h)
{
	int i = 0;

	if (h == NULL)
		return (i);
	while (h != NULL)
	{
		h = h->next;
		i++;
	}
	return (i);
}
/**
 * _strdup - duplicates string
 * @source: string to be duplicated
 * Return: duplicate
 */
char *_strdup(char *source)
{
	int len, i;
	char *new;

	len = strlen(source);
	len++;
	new = malloc(sizeof(char) * len);
	if (new == NULL)
		return (NULL);
	for (i = 0; source[i]; i++)
		new[i] = source[i];
	new[i] = '\0';
	return (new);
}

/**
 * _empty - checks if line is empty
 * @str: string:
 * @delim: string
 * Return: 0 if empty and 1 if not
 */
int _empty(char *str, char *delim)
{
	int i, j;

	for (i = 0; str[i]; i++)
	{
		for (j = 0; delim[j]; j++)
		{
			if (str[i] == delim[j])
				return (0);
		}
	}
	return (1);
}

/**
 * _strsep - alternative for strtok
 * @stringp: pointer
 * @delim: string
 * Return: token
 */
char *_strsep(char **stringp, const char *delim)
{
	char *token;
	char *next;

	if (stringp == NULL || *stringp == NULL)
		return (NULL);

	token = *stringp;
	next = strstr(token, delim);
	if (next != NULL)
	{
		*next = '\0';
		*stringp = (char *)(next + strlen(delim));
	}
	else
		*stringp = NULL;
	return (token);
}
