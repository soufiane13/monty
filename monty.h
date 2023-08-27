#ifndef __MONTY_H__
#define __MONTY_H__
#define _GNU_SOURCE

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define STACK 0
#define QUEUE 1
#define DELIMS " \n\t\a\b"


extern char **op_toks;

/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO Holberton project
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
 * for stack, queues, LIFO, FIFO Holberton project
 */
typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_t **stack, unsigned int number_line);
} instruction_t;


void stack_free(stack_t **stack);
int stack_init(stack_t **stack);
int mode_check(stack_t *stack);
void free_tokens(void);
unsigned int token_arr_len(void);
int run_monty(FILE *script_fd);
void set_op_tok_error(int error_code);


void push_monty(stack_t **stack, unsigned int number_line);
void pall_monty(stack_t **stack, unsigned int number_line);
void pint_monty(stack_t **stack, unsigned int number_line);
void pop_monty(stack_t **stack, unsigned int number_line);
void swap_monty(stack_t **stack, unsigned int number_line);
void add_monty(stack_t **stack, unsigned int number_line);
void nop_monty(stack_t **stack, unsigned int number_line);
void sub_monty(stack_t **stack, unsigned int number_line);
void div_monty(stack_t **stack, unsigned int number_line);
void mul_monty(stack_t **stack, unsigned int number_line);
void mod_monty(stack_t **stack, unsigned int number_line);
void pchar_monty(stack_t **stack, unsigned int number_line);
void pstr_monty(stack_t **stack, unsigned int number_line);
void rotl_monty(stack_t **stack, unsigned int number_line);
void rotr_monty(stack_t **stack, unsigned int number_line);
void stack_monty(stack_t **stack, unsigned int number_line);
void queue_monty(stack_t **stack, unsigned int number_line);


char **strtow(char *str, char *delims);
char *int_get(int n);


int error_usage(void);
int error_malloc(void);
int file_open_error(char *filename);
int unknown_op_error(char *opcode, unsigned int number_line);
int no_int_error(unsigned int number_line);
int error_pop(unsigned int number_line);
int error_pint(unsigned int number_line);
int short_stack_error(unsigned int number_line, char *op);
int error_div(unsigned int number_line);
int error_pchar(unsigned int number_line, char *message);

#endif /* __MONTY_H__ */
