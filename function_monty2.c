#include "monty.h"

void add_monty(stack_t **stack, unsigned int number_line);
void sub_monty(stack_t **stack, unsigned int number_line);
void div_monty(stack_t **stack, unsigned int number_line);
void mul_monty(stack_t **stack, unsigned int number_line);
void mod_monty(stack_t **stack, unsigned int number_line);

/**
 * add_monty - Adds the top two values of a stack_t  .
 * @stack: A pointer to the top mode node of a stack_t  .
 * @number_line: The current working line number of a Monty  file.
 * return: 0
 */
void add_monty(stack_t **stack, unsigned int number_line)
{
	if ((*stack)->next == NULL || (*stack)->next->next == NULL)
	{
		set_op_tok_error(short_stack_error(number_line, "add"));
		return;
	}

	(*stack)->next->next->n += (*stack)->next->n;
	pop_monty(stack, number_line);
}

/**
 * sub_monty - Subtracts the second value from the top of
 *             a stack_t   by the top value.
 * @stack: A pointer to the top mode node of a stack_t  .
 * @number_line: The current working line number of a Monty  file.
 *
 * <return: 0.
 */
void sub_monty(stack_t **stack, unsigned int number_line)
{
	if ((*stack)->next == NULL || (*stack)->next->next == NULL)
	{
		set_op_tok_error(short_stack_error(number_line, "sub"));
		return;
	}

	(*stack)->next->next->n -= (*stack)->next->n;
	pop_monty(stack, number_line);
}

/**
 * div_monty - Divides the second value from the top of
 *             a stack_t   by the top value.
 * @stack: A pointer to the top mode node of a stack_t  .
 * @number_line: The current working line number of a Monty  file.
 *
 * Return: 0 .
 */
void div_monty(stack_t **stack, unsigned int number_line)
{
	if ((*stack)->next == NULL || (*stack)->next->next == NULL)
	{
		set_op_tok_error(short_stack_error(number_line, "div"));
		return;
	}

	if ((*stack)->next->n == 0)
	{
		set_op_tok_error(error_div(number_line));
		return;
	}

	(*stack)->next->next->n /= (*stack)->next->n;
	pop_monty(stack, number_line);
}

/**
 * mul_monty - Multiplies the second value from the top of
 *             a stack_t   by the top value.
 * @stack: A pointer to the top mode node of a stack_t  .
 * @number_line: The current working line number of a Monty  file.
 *
 * Return. 0.
 */
void mul_monty(stack_t **stack, unsigned int number_line)
{
	if ((*stack)->next == NULL || (*stack)->next->next == NULL)
	{
		set_op_tok_error(short_stack_error(number_line, "mul"));
		return;
	}

	(*stack)->next->next->n *= (*stack)->next->n;
	pop_monty(stack, number_line);
}

/**
 * mod_monty - Computes the modulus of the second value from the
 *             top of a stack_t    by the top value.
 * @stack: A pointer to the top mode node of a stack_t  .
 * @number_line: The current working line number of a Monty  file.
 *
 * Return: 0;
 */
void mod_monty(stack_t **stack, unsigned int number_line)
{
	if ((*stack)->next == NULL || (*stack)->next->next == NULL)
	{
		set_op_tok_error(short_stack_error(number_line, "mod"));
		return;
	}

	if ((*stack)->next->n == 0)
	{
		set_op_tok_error(error_div(number_line));
		return;
	}

	(*stack)->next->next->n %= (*stack)->next->n;
	pop_monty(stack, number_line);
}
