#include "monty.h"

/**
 * is_a_number - check for numbers
 *
 * @argument: string to check
 * Return: int 0 or 1
 */
int is_a_number(char *argument)
{
	int pos = 0;

	if (argument == NULL)
		return (0);

	while (argument[pos] != '\0')
	{
		if ((argument[pos] >= 48 && argument[pos] <= 57)
		|| (argument[pos] == '-' && pos == 0))
			pos++;
		else
			return (0);
	}
	return (1);
}

/**
 * push - inserts new node
 *
 * @stack_element: node object
 * @line_number: line number
 */
void push(stack_t **stack_element, unsigned int line_number)
{
	if (carrier.argumen)
	{
		if (!is_a_number(carrier.argumen))
			exit_failure(stack_element, "L%d: usage: push integer\n");
	}
	else
		exit_failure(stack_element, "L%d: usage: push integer\n");
	if (carrier.mode == 's')
		push_to_top(stack_element);
	else
		push_to_bottom(stack_element);
	(void)line_number;
}

/**
 * pop - exit top element of the stack
 *
 * @stack_element : pointer to the stack's top element
 * @line_number: instruction file line number
 */
void pop(stack_t **stack_element, unsigned int line_number)
{
	stack_t *current = *stack_element;

	if (current)
	{
		if (current->next)
			current->next->prev = NULL;
		*stack_element = current->next;
		free(current);
	}
	else
		exit_failure(stack_element, "L%d: can't pop an empty stack\n");
	(void)line_number;
}

/**
 * swap - swap top two elements from the stack
 * @stack_element: stack's header
 * @line_number: line number
 */
void swap(stack_t **stack_element, unsigned int line_number)
{
	int temporal;

	if (*stack_element && (*stack_element)->next)
	{
		temporal = (*stack_element)->n;
		(*stack_element)->n = (*stack_element)->next->n;
		(*stack_element)->next->n = temporal;
	}
	else
		exit_failure(stack_element, "L%d: can't swap, stack too short\n");
	(void)line_number;
}
