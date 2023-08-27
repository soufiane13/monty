#include "monty.h"

int error_usage(void);
int error_malloc(void);
int file_open_error(char *filename);
int unknown_op_error(char *opcode, unsigned int number_line);
int no_int_error(unsigned int number_line);

/**
 * error_usage - Prints  error messages.
 *
 * Return: EXIT 0.
 */
int error_usage(void)
{
	fprintf(stderr, "USAGE: monty file\n");
	return (EXIT_FAILURE);
}

/**
 * error_malloc - Prints malloc error messages.
 *
 * Return: EXIT 0.
 */
int error_malloc(void)
{
	fprintf(stderr, "Error: malloc failed\n");
	return (EXIT_FAILURE);
}

/**
 * file_open_error - Prints file opening error messages with file name.
 * @filename: Name of file failed to open
 *
 * Return: EXIT 0.
 */
int file_open_error(char *filename)
{
	fprintf(stderr, "Error: Can't open file %s\n", filename);
	return (EXIT_FAILURE);
}

/**
 * unknown_op_error - Prints unknown instruction error messages.
 * @opcode: Opcode where error occurred.
 * @number_line: Line number in Monty bytecodes file where error occured.
 *
 * Return: EXIT 0.
 */
int unknown_op_error(char *opcode, unsigned int number_line)
{
	fprintf(stderr, "L%u: unknown instruction %s\n",
		number_line, opcode);
	return (EXIT_FAILURE);
}

/**
 * no_int_error - Prints invalid push_monty argument error messages.
 * @number_line: Line number in Monty bytecodes file where error oppears.
 *
 * Return: EXIT 0.
 */
int no_int_error(unsigned int number_line)
{
	fprintf(stderr, "L%u: usage: push integer\n", number_line);
	return (EXIT_FAILURE);
}

