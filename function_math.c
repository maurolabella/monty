#include "monty.h"

/**
 * _nop - do nothing
 * @stack_element: node header
 * @line_number: instruction line number
 */
void _nop(stack_t **stack_element, unsigned int line_number)
{
	(void)stack_element;
	(void)line_number;
}

/**
 * _add - sum top two nodes
 *
 * @stack_element: node header
 * @line_number: line number
 */
void _add(stack_t **stack_element, unsigned int line_number)
{
	if (*stack_element && (*stack_element)->next)
	{
		(*stack_element)->next->n = (*stack_element)->next->n + (*stack_element)->n;
		(*stack_element) = (*stack_element)->next;
		free((*stack_element)->prev);
		(*stack_element)->prev = NULL;
	}
	else
		exit_failure(stack_element, "L%d: can't add, stack too short\n");
	(void)line_number;
}
