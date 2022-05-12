#include "monty.h"

/**
 * _stack - sets queue mode to stack
 * @stack_element: header
 * @line_number: file incumbent line number
 */
void _stack(stack_t **stack_element, unsigned int line_number)
{
	carrier.mode = 's';
	(void)stack_element;
	(void)line_number;
}

/**
 * _queue - sets queue mode
 * @stack_element: header
 * @line_number: file incumbent line number
 */
void _queue(stack_t **stack_element, unsigned int line_number)
{
	carrier.mode = 'q';
	(void)stack_element;
	(void)line_number;
}
