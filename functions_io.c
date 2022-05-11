#include "monty.h"

/**
 * is_a_number
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
		if ((argument[pos] >= 48 && argument[pos] <= 57) || (argument[pos] == '-' && pos == 0))
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
	stack_t *new_node;
	int new_n;
	if (carrier.argumen)
	{
		if(!is_a_number(carrier.argumen))
			exit_failure(stack_element, "L%d: usage: push integer\n");
		else
			new_n = atoi(carrier.argumen);
	}
	else
		exit_failure(stack_element, "L%d: usage: push integer\n");
	new_node = malloc(sizeof(stack_t));
	if(!new_node)
	{
		fprintf(stderr,"Error: malloc failed\n");
		free_all(stack_element);
		exit(EXIT_FAILURE);
	}
	new_node->prev = NULL;
	new_node->n = new_n;
	new_node->next = *stack_element;
	if(!(*stack_element))
		*stack_element = new_node;
	else
	{
		(*stack_element)->prev = new_node;
		*stack_element = new_node;
	}
	(void) line_number;
}

/**
 * pop - exit top element of the stack
 * 
 * @stack_element : pointer to the stack's top element 
 * @pline_number: instruction file line number 
 */
void pop(stack_t **stack_element, unsigned int line_number)
{
	stack_t *current = *stack_element;

	if (current)
	{
		if(current->next)
			current->next->prev = NULL;
		*stack_element = current->next;
		free(current);
	}
	else
		exit_failure(stack_element, "L%d: can't pop an empty stack\n");
	(void) line_number;
}
