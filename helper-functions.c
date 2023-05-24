#include "monty.h"
/**
 * _is_digit - checks if string has only digits
 * @s: string
 * Return: 1 if all are digits
 */
int _is_digit(char *s)
{

	int j, i = 0;

	while (s[i])
		i++;
	for (j = 0; j < i; j++)
	{
		if (s[j] >= 48 && s[j] <= 57)
		{
		}
		else
			return (0);
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
