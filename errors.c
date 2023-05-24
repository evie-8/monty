#include "monty.h"
/**
 * arg_error - error for number of arguments
 * Return: failure
 */
int arg_error(void)
{
	fprintf(stderr, "USAGE: monty file\n");
	return (EXIT_FAILURE);
}

/**
 * open_error - error due to failure to open file
 * @filename: name of file
 * Return: failure code
 */
int open_error(char *filename)
{
	fprintf(stderr, "Error: Can't open file %s\n", filename);
	return (EXIT_FAILURE);
}


/**
 * mem_error - error due to failure to allocate memory
 * Return: failure code
 */
int mem_error(void)
{
	fprintf(stderr, "Error: malloc failed\n");
	return (EXIT_FAILURE);
}
