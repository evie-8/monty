#include "monty.h"
/**
 * main - check code
 * @ac: number of command line arguments
 * @argv: array storing command line arguments
 * Return: 0 success
 */
int main(int ac, char *argv[])
{
	FILE *file;

	if (ac != 2)
		arg_error();
	file = fopen(argv[1], "r");
	if (file == NULL)
		open_error(argv[1]);
	execute_monty(file);
	if (file != NULL)
		fclose(file);
	return (0);
}
