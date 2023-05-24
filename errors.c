#include "monty.h"
/**
 * arg_error - error for number of arguments
 */
void arg_error(void)
{
	fprintf(stderr, "USAGE: monty file\n");
	 exit(EXIT_FAILURE);
}

/**
 * open_error - error due to failure to open file
 * @filename: name of file
 */
void open_error(char *filename)
{
	fprintf(stderr, "Error: Can't open file %s\n", filename);
	exit(EXIT_FAILURE);
}


/**
 * mem_error - error due to failure to allocate memory
 */
void mem_error(void)
{
	fprintf(stderr, "Error: malloc failed\n");
	exit(EXIT_FAILURE);
}

/**
 * opcode_error - error due to failure to unknown opcode
 *@line: line number
 * @opcode: string
 */
void opcode_error(int line, char *opcode)
{
	fprintf(stderr, "L%d: unknown instruction %s\n", line, opcode);
	 exit(EXIT_FAILURE);
}
