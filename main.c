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
	printf(argv[1]);
	file_process(argv[1]);
	return (EXIT_SUCCESS);
}

/**
 * file_failure - triggers response to file failure 
 * 
 * @filename: file header received 
 * @stack_element: pointer to stack received 
 */
void file_failure(FILE *filename, stack_t *stack_element)
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
	if(control == 0)
	{
		/**check if it is a regular file**/
		if((st.st_mode & S_IFMT) != S_IFREG)
			file_failure(filename, &stack_element);
		else
			file_failure(filename, &stack_element);
		carrier.fd = fopen(filename,"r");
		if(carrier.fd == NULL)
			file_failure(filename, &stack_element);
		carrier.nro_line=0;
		into_file(&stack_element);
		free_all(&stack_element);
		return("Success");
	}

	
	
	



}