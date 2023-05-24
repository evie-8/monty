#ifndef MONTY_H
#define MONTY_H

#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>

#define  MAX 256

/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO
 */
typedef struct stack_s
{
	int n;
	struct stack_s *prev;
	struct stack_s *next;
} stack_t;

/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO
 */
typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

/* function prototypes */
char **tokenize(char *command, char *delim);
char **toke(char *command, char *delim);
void frees(char **argv);
int execute_monty(FILE *data);
int _is_digit(char *s);
int run_monty(unsigned int line_number, char **argv, stack_t **stack);
void free_stack(stack_t *head);
size_t stack_len(stack_t *h);
char *_strdup(char *source);
int _empty(char *str, char *delim);
char *_strsep(char **stringp, const char *delim);

/* error functions */
void arg_error(void);
void open_error(char *filename);
void mem_error(void);
void opcode_error(int line, char *opcode);

/* stacks: 0-stack_functions.c */
int stack_push(char *token, stack_t **stack, unsigned int line_number);
void pall(stack_t **stack, unsigned int line_number);
void pint(stack_t **stack, unsigned int line_number);
void stack_pop(stack_t **stack, unsigned int line_number);
void swap(stack_t **stack, unsigned int line_number);

/* 2-more_functions.c */
void addition(stack_t **stack, unsigned int line_number);
void subtraction(stack_t **stack, unsigned int line_number);
void division(stack_t **stack, unsigned int line_number);
void mult(stack_t **stack, unsigned int line_number);
void modulus(stack_t **stack, unsigned int line_number);

/* 4-stack_functions.c */
void print_char(stack_t **stack, unsigned int line_number);
void print_str(stack_t **stack, unsigned int line_number);
void rotate1(stack_t **stack, unsigned int line_number);
void rotate2(stack_t **stack, unsigned int line_number);
int q_push(char *token, stack_t **stack, unsigned int line_number);
#endif
