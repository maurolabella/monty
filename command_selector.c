#include "monty.h"

/**
 * command_selector - select proper function
 *
 * @command: received argument to make selection
 * Return: void
 */
void (*command_selector(char *command))(stack_t **, unsigned int)
{
	int i = 0;
	instruction_t commands[] = {
			{"push", push},
			{"pall", pall},
			{"pint", pint},
			{"pop", pop},
			{"swap", swap},
			/**
			 *{"add", _add},
			 *{"sub", _sub},
			 *{"div", _div},
			 *{"mod", _mod},
			 *{"mul", _mul},
			 *{"pchar", pchar},
			 *{"pstr", pstr},
			 *{"nop", _nop},
			 *{"rot1", rot1},
			 *{"rotr", rotr},
			 */
			{NULL, NULL}};
	while (commands[i].f != NULL)
	{
		if (strcmp(command, commands[i].opcode) == 0)
			return (commands[i].f);
		i++;
	}
	return (NULL);
}
