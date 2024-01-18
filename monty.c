#include "monty.h"

/**
 * main - Entry point of the Monty interpreter
 * @argc: The number of command-line arguments
 * @argv: An array of strings containing the command-line arguments
 *
 * Description:
 *   This function serves as the entry point for the Monty interpreter.
 *   It validates the input, sets the filename from the command-line argument,
 *   calls the parse function to process the Monty file, and returns 0 on
 *   success.
 *
 * Return: 0 on success, EXIT_FAILURE on failure
 */
int main(int argc, char *argv[])
{
	/* validate inpput: check if the number of arguments is not 2 */
	if (argc != 2)
	{

		fprintf(stderr, "Usage: monty file\n");
		exit(EXIT_FAILURE);
	}

	/* Set the filename from the command-line argument */
	monty.filename = argv[1];

	/* Call the `parse_input` function to process the Monty file */
	parse_input();

	free_stack(&monty.head);

	return (0); /* Return 0 to indicate successful execution */
}
