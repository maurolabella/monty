#include "monty.h"

/**
 * free_stack_t - frees the stack
 *
 * @stack_elem: receives the header pointing at stack
 */
void free_stack_t(stack_t **stack_elem)
{
	stack_t *current = *stack_elem;

	while (current)
	{
		current = (*stack_elem)->next;
		free(*stack_elem);
		(*stack_elem) = current;
	}
}

/**
 * free_all - frees both stack and carrier
 *
 * @stack_elem: receives the header pointing at stack
 */
void free_all(stack_t **stack_elem)
{
	free_stack_t(stack_elem);
	if (carrier.buffer)
		free(carrier.buffer);
	if (carrier.fd)
		fclose(carrier.fd);
}