#ifndef _MONTY_
#define _MONTY_
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include <sys/types.h>

/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO
 */
typedef struct stack_s
{
	int n;
	struct stack_s *prev;
	struct stack_s *next;
} stack_t;

/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO
 */
typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

/**
 * struct cart - main holder for free and exit procedures
 * @nro_line: nro line related to the file instructions
 * @buffer: line read from file
 * @argumen:tokens captured from line
 * @fd:monty instruction file
 */
typedef struct cart
{
	int nro_line;
	char *buffer;
	char *argumen;
	FILE *fd;
	char mode;
} cart_t;

cart_t carrier;

/** main driver **/
void file_failure(char *filename, stack_t **stack_element);
char *file_process(char *filename);
int not_commented(char *str);
void line_tokenizer(stack_t **stack_element);

/** free memory process **/
void free_stack_t(stack_t **stack_elem);
void free_all(stack_t **stack_elem);

/** command selector **/
void (*command_selector(char *command))(stack_t **, unsigned int);

/** i/o functions**/
int is_a_number(char *argument);
void push(stack_t **stack_element, unsigned int line_number);
void pop(stack_t **stack_element, unsigned int line_number);
void swap(stack_t **stack_element, unsigned int line_number);

/** push functions */
void push_to_top(stack_t **stack_element);
void push_to_bottom(stack_t **stack_element);


/** print functions **/
void pall(stack_t **stack_element, unsigned int line_number);
void pint(stack_t **stack_element, unsigned int line_number);
void pchar(stack_t **stack_element, unsigned int line_number);
void pstr(stack_t **stack_element, unsigned int line_number);

/** math functions **/
void _nop(stack_t **stack_element, unsigned int line_number);
void _add(stack_t **stack_element, unsigned int line_number);
void _sub(stack_t **stack_element, unsigned int line_number);
void _div(stack_t **stack_element, unsigned int line_number);
void _mul(stack_t **stack_element, unsigned int line_number);
void _mod(stack_t **stack_element, unsigned int line_number);

/** list node functions **/
int count_nodes(stack_t **stack_element);
void rotl(stack_t **stack_element, unsigned int line_number);
void rotr(stack_t **stack_element, unsigned int line_number);

/** queue order mode functions **/
void _stack(stack_t **stack_element, unsigned int line_number);
void _queue(stack_t **stack_element, unsigned int line_number);

/** exit functions **/
void exit_failure(stack_t **stack_element, const char *message);

#endif
