#include "monty.h"

/**
 * push_to_top - inserts new node at the top
 * @stack_element: node object
 */
void push_to_top(stack_t **stack_element)
{
	stack_t *new_node;
	int new_n = atoi(carrier.argumen);

	new_node = malloc(sizeof(stack_t));
	if (!new_node)
	{
		fprintf(stderr, "Error: malloc failed\n");
		free_all(stack_element);
		exit(EXIT_FAILURE);
	}
	new_node->prev = NULL;
	new_node->n = new_n;
	new_node->next = *stack_element;
	if (!(*stack_element))
		*stack_element = new_node;
	else
	{
		(*stack_element)->prev = new_node;
		*stack_element = new_node;
	}
}

/**
 * push_to_bottom - inserts new node at the bottom
 * @stack_element: node object
 */
void push_to_bottom(stack_t **stack_element)
{
	stack_t *new_node, *indicator;
	int new_n = atoi(carrier.argumen);

	new_node = malloc(sizeof(stack_t));
	if (!new_node)
	{
		fprintf(stderr, "Error: malloc failed\n");
		free_all(stack_element);
		exit(EXIT_FAILURE);
	}
	new_node->prev = NULL;
	new_node->n = new_n;
	new_node->next = NULL;
	if (!(*stack_element))
		*stack_element = new_node;
	else
	{
		indicator = *stack_element;
		while (indicator->next)
			indicator = indicator->next;
		new_node->prev = indicator;
		indicator->next = new_node;
	}
}
