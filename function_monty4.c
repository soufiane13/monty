#include "monty.h"

void rotl_monty(stack_t **stack, unsigned int line_number);
void rotr_monty(stack_t **stack, unsigned int line_number);
void stack_monty(stack_t **stack, unsigned int line_number);
void queue_monty(stack_t **stack, unsigned int line_number);

/**
 * rotl_monty - Rotates the top value of a stack_t   to the bottom.
 * @stack: A pointer to the top mode node of a stack_t  .
 * @line_number: The current working line number of a Monty  file.
 */
void rotl_monty(stack_t **stack, unsigned int line_number)
{
	stack_t *top, *bottom;

	if ((*stack)->next == NULL || (*stack)->next->next == NULL)
		return;

	top = (*stack)->next;
	bottom = (*stack)->next;
	while (bottom->next != NULL)
		bottom = bottom->next;

	top->next->prev = *stack;
	(*stack)->next = top->next;
	bottom->next = top;
	top->next = NULL;
	top->prev = bottom;

	(void)line_number;
}

/**
 * rotr_monty - Rotates the bottom value of a   list to the top.
 * @stack: A pointer to the top mode node of a   list.
 * @line_number: The current working line number of a Monty  file.
 */
void rotr_monty(stack_t **stack, unsigned int line_number)
{
	stack_t *top, *bottom;

	if ((*stack)->next == NULL || (*stack)->next->next == NULL)
		return;

	top = (*stack)->next;
	bottom = (*stack)->next;
	while (bottom->next != NULL)
		bottom = bottom->next;

	bottom->prev->next = NULL;
	(*stack)->next = bottom;
	bottom->prev = *stack;
	bottom->next = top;
	top->prev = bottom;

	(void)line_number;
}

/**
 * stack_monty - Converts a queue to a stack.
 * @stack: A pointer to the top mode node of a stack_t  .
 * @line_number: The current working line number of a Monty  file.
 */
void stack_monty(stack_t **stack, unsigned int line_number)
{
	(*stack)->n = STACK;
	(void)line_number;
}

/**
 * queue_monty - Converts a stack to a queue.
 * @stack: A pointer to the top mode node of a stack_t  .
 * @line_number: The current working line number of a Monty  file.
 */
void queue_monty(stack_t **stack, unsigned int line_number)
{
	(*stack)->n = QUEUE;
	(void)line_number;
}
