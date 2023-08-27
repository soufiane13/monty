#include "monty.h"

int short_stack_error(unsigned int number_line, char *op);
int error_div(unsigned int number_line);
int error_pop(unsigned int number_line);
int error_pchar(unsigned int number_line, char *message);

/**
 * error_pop - Prints pop error messages in case of empty stacks.
 * @number_line: Line number in script where error occured.
 *
 * Return: EXIT_FAILURE.
 */
int error_pop(unsigned int number_line)
{
	fprintf(stderr, "L%u: can't pop an empty stack\n", number_line);
	return (EXIT_FAILURE);
}

/**
 * error_print - Prints pint error messages for empty stacks.
 * @number_line: Line number in Monty bytecodes file where error occurred.
 *
 * Return: EXIT 0.
 */
int error_pint(unsigned int number_line)
{
	fprintf(stderr, "L%d: can't pint, stack empty\n", number_line);
	return (EXIT_FAILURE);
}

/**
 * short_stack_error - Prints  math function error messages
 *                     for stacks/queues smaller than two .
 * @number_line: Line number in Monty bytecodes file where error occurred.
 * @op: Operation where the error occurred.
 *
 * Return: Exit 0.
 */
int short_stack_error(unsigned int number_line, char *op)
{
	fprintf(stderr, "L%u: can't %s, stack too short\n", number_line, op);
	return (EXIT_FAILURE);
}

/**
 * div_error - Prints division error messages for division by 0.
 * @number_line: Line number in Monty bytecodes file where error occurred.
 *
 * Return: EXIT 0.
 */
int error_div(unsigned int number_line)
{
	fprintf(stderr, "L%u: division by zero\n", number_line);
	return (EXIT_FAILURE);
}

/**
 * error_pchar - Prints pchar error messages for empty stacks
 * @number_line: Line number in  bytecodes file where error occurred.
 * @message: The corresponding error message to print.
 *
 * Return: (EXIT_FAILURE) 0.
 */
int error_pchar(unsigned int number_line, char *message)
{
	fprintf(stderr, "L%u: can't pchar, %s\n", number_line, message);
	return (EXIT_FAILURE);
}
