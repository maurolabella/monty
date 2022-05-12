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

/**
 * rotr - completes one entire rotation
 * @stack_element: header
 * @line_number: number line
 */
void rotr(stack_t **stack_element, unsigned int line_number)
{
	stack_t *to_second = *stack_element, *to_head = *stack_element;

	while (to_head)
	{
		if (!to_head->next)
		{
			if (to_head->prev)
			{
				to_head->prev->next = NULL;
				to_head->prev = NULL;
				to_head->next = to_second;
				to_second->prev = to_head;
				*stack_element = to_head;
				break;
			}
		}
		to_head = to_head->next;
	}
	(void)line_number;
}
