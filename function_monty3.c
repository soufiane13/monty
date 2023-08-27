#include "monty.h"

void nop_monty(stack_t **stack, unsigned int line_number);
void pchar_monty(stack_t **stack, unsigned int line_number);
void pstr_monty(stack_t **stack, unsigned int line_number);

/**
 * nop_monty - Does  nothing for the Monty opcode.
 * @stack: A pointer to the top mode node of a stack_t  .
 * @line_number: The current working line number of a Monty  file.
 */
void nop_monty(stack_t **stack, unsigned int line_number)
{
	(void)stack;
	(void)line_number;
}

/**
 * pchar_monty - Prints the character in the top value
 *               node of a stack_t  .
 * @stack: A pointer to the top mode node of a stack_t  .
 * @line_number: The current working line number of a Monty  file.
 */
void pchar_monty(stack_t **stack, unsigned int line_number)
{
	if ((*stack)->next == NULL)
	{
		set_op_tok_error(error_pchar(line_number, "stack empty"));
		return;
	}
	if ((*stack)->next->n < 0 || (*stack)->next->n > 127)
	{
		set_op_tok_error(error_pchar(line_number,
					     "value out of range"));
		return;
	}

	printf("%c\n", (*stack)->next->n);
}

/**
 * pstr_monty - Prints the string contained in a stack_t  .
 * @stack: A pointer to the top mode node of a stack_t  .
 * @line_number: The current working line number of a Monty  file.
 */
void pstr_monty(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp = (*stack)->next;

	while (tmp && tmp->n != 0 && (tmp->n > 0 && tmp->n <= 127))
	{
		printf("%c", tmp->n);
		tmp = tmp->next;
	}

	printf("\n");

	(void)line_number;
}
