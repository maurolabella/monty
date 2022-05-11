#include "monty.h"

/**
 * main - principal function
 *
 * @argc: number or arguments
 * @argv: file names as arguments
 * Return: int 0 upon execution
 */
int main(int argc, char **argv)
{
	if (argc != 2)
	{
		fprintf(stderr, "%s\n", "USAGE: monty file");
		exit(EXIT_FAILURE);
	}
	file_process(argv[1]);
	return (EXIT_SUCCESS);
}

/**
 * file_failure - triggers response to file failure
 *
 * @filename: file header received
 * @stack_element: pointer to stack received
 */
void file_failure(char *filename, stack_t **stack_element)
{
	fprintf(stderr, "Error: Can't open file %s\n", filename);
	free_all(stack_element);
	exit(EXIT_FAILURE);
}

/**
 * file_process - process content of main argument file
 *
 * @filename: path to a file
 * Return: char* string with result description
 */
char *file_process(char *filename)
{
	struct stat st;
	int control;
	stack_t *stack_element = NULL;

	control = stat(filename, &st);
	if (control == 0)
	{
		/**check if it is a regular file**/
		if ((st.st_mode & S_IFMT) != S_IFREG)
			file_failure(filename, &stack_element);
	}
	else
		file_failure(filename, &stack_element);
	carrier.fd = fopen(filename, "r");
	if (carrier.fd == NULL)
		file_failure(filename, &stack_element);
	carrier.nro_line = 0;
	line_tokenizer(&stack_element);
	free_all(&stack_element);
	return ("Success");
}

/**
 * not_commented - look for comments #
 *
 * @str: string to be controlled
 * Return: int 0 if comments #initialized are found
 */
int not_commented(char *str)
{
	while (*str != '\0')
	{
		if (*str == '#')
			return (0);
		str++;
	}
	return (1);
}

void line_tokenizer(stack_t **stack_element)
{
	char *command = NULL;
	size_t buffer_size = 1024;
	void (*f)(stack_t **, unsigned int);

	carrier.buffer = NULL, carrier.argumen = NULL;
	carrier.buffer = malloc(sizeof(char) * buffer_size);
	if (carrier.buffer == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		free_all(stack_element);
		exit(EXIT_FAILURE);
	}
	while (getline(&carrier.buffer, &buffer_size, carrier.fd) != -1)
	{
		carrier.nro_line++;
		if (not_commented(carrier.buffer))
		{
			command = strtok(carrier.buffer, "\v\f\n\t\r ");
			carrier.argumen = strtok(NULL, "\v\f\n\t\r ");
			if (command)
			{
				f = command_selector(command);
				if (f)
					f(stack_element, (unsigned int)carrier.nro_line);
				else
				{
					fprintf(stderr, "L%d: unknown instruction %s\n", carrier.nro_line, command);
					free_all(stack_element);
					exit(EXIT_FAILURE);
				}
			}
		}
	}
}
