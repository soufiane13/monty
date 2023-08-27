#include "monty.h"
#include <string.h>

void stack_free(stack_t **stack);
int stack_init(stack_t **stack);
int mode_check(stack_t *stack);

/**
 * stack_free - Frees a stack_t stack.
 * @stack: A pointer to the top (stack) or
 *         bottom (queue) of a stack_t.
 */
void stack_free(stack_t **stack)
{
	stack_t *tmp = *stack;

	while (*stack)
	{
		tmp = (*stack)->next;
		free(*stack);
		*stack = tmp;
	}
}

/**
 * stack_init - Initializes a stack_t  with beginning
 *              stack and ending queue nodes.
 * @stack: A pointer to an unitialized stack_t .
 *
 * Return:  error occurs - EXIT_FAILURE.
 *         or - EXIT_SUCCESS.
 */
int stack_init(stack_t **stack)
{
	stack_t *s;

	s = malloc(sizeof(stack_t));
	if (s == NULL)
		return (error_malloc());

	s->n = STACK;
	s->prev = NULL;
	s->next = NULL;

	*stack = s;

	return (EXIT_SUCCESS);
}

/**
 * mode_check - Checks if a stack_t linked  is in stack or queue mode.
 * @stack: A pointer to the top (stack) or bottom (queue)
 *         of a stack_t  .
 *
 * Return:  STACK (0).
 *         I QUEUE (1).
 *         or - 2.
 */
int mode_check(stack_t *stack)
{
	if (stack->n == STACK)
		return (STACK);
	else if (stack->n == QUEUE)
		return (QUEUE);
	return (2);
}
