#include "monty.h"
/**
 * main - check code
 * @ac: number of command line arguments
 * @argv: array storing command line arguments
 * Return: 0 success
 */
int main(int ac, char *argv[])
{
	int open_id, read_id;
	char buffer[SIZE];

	if (ac != 2)
		return (arg_error());
	open_id = open(argv[1], O_RDONLY);
	if (open_id == -1)
		return (open_error(argv[1]));
	read_id = read(open_id, buffer, SIZE);
	if (read_id == -1)
	{
		close(open_id);
		return (EXIT_FAILURE);
	}
	buffer[read_id - 1] = '\0';
	close(open_id);
	execute_monty(buffer);
	return (0);
}
