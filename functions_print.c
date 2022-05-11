#include "monty.h"

/**
 * pall - print all the stack
 *
 * @stack_element: header to stack
 * @line_number: number of line original file
 */
void pall(stack_t **stack_element, unsigned int line_number)
{
	stack_t *current = *stack_element;

	while (current)
	{
		printf("%d\n", current->n);
		current = current->next;
	}
	(void)line_number;
}

/**
 * pint - print top element
 *
 * @stack_element: header to stack
 * @line_number: number of line original file
 */
void pint(stack_t **stack_element, unsigned int line_number)
{
	stack_t *current = *stack_element;

	if (current)
		printf("%d\n", current->n);
	else
		exit_failure(stack_element, "L%d: can't pint, stack empty\n");
	(void)line_number;
}
