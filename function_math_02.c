#include "monty.h"

/**
 * _mul - sum top two nodes
 *
 * @stack_element: node header
 * @line_number: line number
 */
void _mul(stack_t **stack_element, unsigned int line_number)
{
	if (*stack_element && (*stack_element)->next)
	{
		(*stack_element)->next->n = (*stack_element)->next->n * (*stack_element)->n;
		(*stack_element) = (*stack_element)->next;
		free((*stack_element)->prev);
		(*stack_element)->prev = NULL;
	}
	else
		exit_failure(stack_element, "L%d: can't mul, stack too short\n");
	(void)line_number;
}

/**
 * _mod - sum top two nodes
 *
 * @stack_element: node header
 * @line_number: line number
 */
void _mod(stack_t **stack_element, unsigned int line_number)
{
	if (*stack_element && (*stack_element)->next)
	{
		if ((*stack_element)->n == 0)
			exit_failure(stack_element, "L%d: division by zero\n");

		(*stack_element)->next->n = (*stack_element)->next->n % (*stack_element)->n;
		(*stack_element) = (*stack_element)->next;
		free((*stack_element)->prev);
		(*stack_element)->prev = NULL;
	}
	else
		exit_failure(stack_element, "L%d: can't mod, stack too short\n");
	(void)line_number;
}
