#include "monty.h"
#include <string.h>

void free_tokens(void);
unsigned int token_arr_len(void);
int is_empty_line(char *line, char *delims);
void (*get_op_func(char *opcode))(stack_t**, unsigned int);
int run_monty(FILE *script_fd);

/**
 * free_tokens - Frees the global op_toks array of strings.
 * Return : 0.
 */
void free_tokens(void)
{
	size_t i = 0;

	if (op_toks == NULL)
		return;

	for (i = 0; op_toks[i]; i++)
		free(op_toks[i]);

	free(op_toks);
}

/**
 * token_arr_len - Gets the length of current op_toks.
 *
 * Return: integr Length of current op_toks .
 */
unsigned int token_arr_len(void)
{
	unsigned int toks_len = 0;

	while (op_toks[toks_len])
		toks_len++;
	return (toks_len);
}

/**
 * is_empty_line - Checks if a line read from getline only contains delimiters.
 * @line: A pointer to the line.
 * @delims: A string of delimiter characters.
 *
 * Return: If the line only contains delimiters - 1.
 *         Or - 0.
 */
int is_empty_line(char *line, char *delims)
{
	int i, j;

	for (i = 0; line[i]; i++)
	{
		for (j = 0; delims[j]; j++)
		{
			if (line[i] == delims[j])
				break;
		}
		if (delims[j] == '\0')
			return (0);
	}

	return (1);
}

/**
 * get_op_func - Matches an opcode with its corresponding function.
 * @opcode: The opcode to match.
 *
 * Return: A pointer to the  function.
 */
void (*get_op_func(char *opcode))(stack_t**, unsigned int)
{
	instruction_t op_funcs[] = {
		{"push", push_monty},
		{"pall", pall_monty},
		{"pint", pint_monty},
		{"pop", pop_monty},
		{"swap", swap_monty},
		{"add", add_monty},
		{"nop", nop_monty},
		{"sub", sub_monty},
		{"div", div_monty},
		{"mul", mul_monty},
		{"mod", mod_monty},
		{"pchar", pchar_monty},
		{"pstr", pstr_monty},
		{"rotl", rotl_monty},
		{"rotr", rotr_monty},
		{"stack", stack_monty},
		{"queue", queue_monty},
		{NULL, NULL}
	};
	int i;

	for (i = 0; op_funcs[i].opcode; i++)
	{
		if (strcmp(opcode, op_funcs[i].opcode) == 0)
			return (op_funcs[i].f);
	}

	return (NULL);
}

/**
 * monty_run - Primary function to execute a Monty  script.
 * @script_fd: File descriptor for an open Monty  script.
 *
 * Return: EXIT_SUCCESS on success,on failure respective error code .
 */
int run_monty(FILE *script_fd)
{
	stack_t *stack = NULL;
	char *line = NULL;
	size_t len = 0, exit_status = EXIT_SUCCESS;
	unsigned int number_line = 0, prev_tok_len = 0;
	void (*op_func)(stack_t**, unsigned int);

	if (stack_init(&stack) == EXIT_FAILURE)
		return (EXIT_FAILURE);

	while (getline(&line, &len, script_fd)!= -1 )
	{
		number_line++;
		op_toks = strtow(line, DELIMS);
		if (op_toks == NULL)
		{
			if (is_empty_line(line, DELIMS))
				continue;
			stack_free(&stack);
			return (error_malloc());
		}
		else if (op_toks[0][0] == '#') 
		{
			free_tokens();
			continue;
		}
		op_func = get_op_func(op_toks[0]);
		if (op_func == NULL)
		{
			stack_free(&stack);
			exit_status = unknown_op_error(op_toks[0], number_line);
			free_tokens();
			break;
		}
		prev_tok_len = token_arr_len();
		op_func(&stack, number_line);
		if (token_arr_len() != prev_tok_len)
		{
			if (op_toks && op_toks[prev_tok_len])
				exit_status = atoi(op_toks[prev_tok_len]);
			else
				exit_status = EXIT_FAILURE;
			free_tokens();
			break;
		}
		free_tokens();
	}
	stack_free(&stack);

	if (line && *line == 0)
	{
		free(line);
		return (error_malloc());
	}

	free(line);
	return (exit_status);
}
