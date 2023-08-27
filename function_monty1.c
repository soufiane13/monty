#include "monty.h"

void push_monty(stack_t **stack, unsigned int number_line);
void pall_monty(stack_t **stack, unsigned int number_line);
void pint_monty(stack_t **stack, unsigned int number_line);
void pop_monty(stack_t **stack, unsigned int number_line);
void swap_monty(stack_t **stack, unsigned int number_line);

/**
 * push_monty - Pushes a value to a stack_t 
 * @stack: A pointer to the top mode node of a stack_t 
 * @number_line: The current working line number of a Monty  file.
 */
void push_monty(stack_t **stack, unsigned int number_line)
{
	stack_t *tmp, *new;
	int i;

	new = malloc(sizeof(stack_t));
	if (new == NULL)
	{
		set_op_tok_error(error_malloc());
		return;
	}

	if (op_toks[1] == NULL)
	{
		set_op_tok_error(no_int_error(number_line));
		return;
	}

	for (i = 0; op_toks[1][i]; i++)
	{
		if (op_toks[1][i] == '-' && i == 0)
			continue;
		if (op_toks[1][i] < '0' || op_toks[1][i] > '9')
		{
			set_op_tok_error(no_int_error(number_line));
			return;
		}
	}
	new->n = atoi(op_toks[1]);

	if (mode_check(*stack) == STACK) 
	{
		tmp = (*stack)->next;
		new->prev = *stack;
		new->next = tmp;
		if (tmp)
			tmp->prev = new;
		(*stack)->next = new;
	}
	else 
	{
		tmp = *stack;
		while (tmp->next)
			tmp = tmp->next;
		new->prev = tmp;
		new->next = NULL;
		tmp->next = new;
	}
}

/**
 * pall_monty - Prints the values of a stack_t .
 * @stack: A pointer to the top mode node of a stack_t .
 * @number_line: The current working line number of a Monty  file.
 */
void pall_monty(stack_t **stack, unsigned int number_line)
{
	stack_t *tmp = (*stack)->next;

	while (tmp)
	{
		printf("%d\n", tmp->n);
		tmp = tmp->next;
	}
	(void)number_line;
}

/**
 * pint_monty - Prints the top value of a stack_t  .
 * @stack: A pointer to the top mode node of a stack_t  .
 * @number_line: The current working line number of a Monty  file.
 */
void pint_monty(stack_t **stack, unsigned int number_line)
{
	if ((*stack)->next == NULL)
	{
		set_op_tok_error(error_pint(number_line));
		return;
	}

	printf("%d\n", (*stack)->next->n);
}


/**
 * pop_monty - Removes the top value element of a stack_t  .
 * @stack: A pointer to the top mode node of a stack_t  .
 * @number_line: The current working line number of a Monty  file.
 */
void pop_monty(stack_t **stack, unsigned int number_line)
{
	stack_t *next = NULL;

	if ((*stack)->next == NULL)
	{
		set_op_tok_error(error_pop(number_line));
		return;
	}

	next = (*stack)->next->next;
	free((*stack)->next);
	if (next)
		next->prev = *stack;
	(*stack)->next = next;
}

/**
 * swap_monty - Swaps the top two value elements of a stack_t  .
 * @stack: A pointer to the top mode node of a stack_t  .
 * @number_line: The current working line number of a Monty  file.
 */
void swap_monty(stack_t **stack, unsigned int number_line)
{
	stack_t *tmp;

	if ((*stack)->next == NULL || (*stack)->next->next == NULL)
	{
		set_op_tok_error(short_stack_error(number_line, "swap"));
		return;
	}

	tmp = (*stack)->next->next;
	(*stack)->next->next = tmp->next;
	(*stack)->next->prev = tmp;
	if (tmp->next)
		tmp->next->prev = (*stack)->next;
	tmp->next = (*stack)->next;
	tmp->prev = *stack;
	(*stack)->next = tmp;
}
