#include "monty.h"

/**
 * count_nodes - count list nodes
 * @stack_element: list header
 * Return: integer enumerating node's list
 */
int count_nodes(stack_t **stack_element)
{
	stack_t *current = *stack_element;
	int i = 0;

	while (current)
	{
		i++;
		current = current->next;
	}
	return (i);
}

/**
 * rotl - one movement rotation
 * @stack_element: header
 * @line_number: number line
 */
void rotl(stack_t **stack_element, unsigned int line_number)
{
	stack_t *moving = *stack_element, *target_position = *stack_element;

	if (count_nodes(stack_element) < 2)
		return;
	*stack_element = (*stack_element)->next;
	(*stack_element)->prev = NULL;
	while (target_position->next)
		target_position = target_position->next;
	moving->prev = target_position;
	moving->next = NULL;
	target_position->next = moving;
	(void)line_number;
}
