#include "monty.h"

/**
 * exit_failure - exits and print message accordint to parameters
 *
 * @stack_element - pointer to node structure
 * @message: message to be displayes with fprintf
 */
void exit_failure(stack_t **stack_element, const char *message)
{
	fprintf(stderr, message, carrier.nro_line);
	free_all(stack_element);
	exit(EXIT_FAILURE);
}