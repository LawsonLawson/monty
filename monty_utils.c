#include "monty.h"

/**
 * parse_input - Reads and processes input commands from a Monty file.
 *
 * Description:
 *   This function opens a Monty file for reading, allocates memory for a
 *   buffer to store input lines, and then reads and processes each line from
 *   the file. It also handles errors related to file opening, memory
 *   allocation, and reading.
 */
void parse_input(void)
{
	ssize_t bytes_read;
	size_t size = BUFFER_SIZE;

	/* Open the Monty file for reading */
	monty.file_pointer = fopen(monty.filename, "r");
	if (!monty.file_pointer)
	{
		fprintf(stderr, "Error: Can't open file %s\n", monty.filename);
		exit(EXIT_FAILURE);
	}

	/* Allocate memory for the buffer to store input lines */
	monty.buffer = _calloc(size, sizeof(char));
	if (!monty.buffer)
	{
		fprintf(stderr, "Error: malloc failed\n");
		fclose(monty.file_pointer);
		exit(EXIT_FAILURE);
	}
	/* Read and process each line from the Monty file */
	while ((bytes_read = getline(&monty.buffer, &size, monty.file_pointer)) != -1)
	{
		++monty.line_number;
		execute_command(monty.buffer);
	}

	/* Handle errors during reading from the file */
	if (bytes_read == -1)
	{
		if (ferror(monty.file_pointer))
			fprintf(stderr, "Error: readindg from file failed\n");
		else if (errno == ENOMEM)
			fprintf(stderr, "Error: malloc failed\n");

		fclose(monty.file_pointer);
		exit(EXIT_FAILURE);
	}

	fclose(monty.file_pointer);
	monty.destroy((void **)&monty.buffer);
}


/**
 * execute_command - Executes a Monty command based on the provided opcode.
 * @command: The string containing the Monty command.
 *
 * Description:
 *   This function takes a Monty command as input, tokenizes it to extract the
 *   opcode, and executes the corresponding operation based on the opcode.
 *   It supports various opcodes such as "push" and "pall," and it dynamically
 *   calls the associated functions. Additionally, it handles errors for
 *   unknown instructions and provides proper error messages with line numbers.
 */
void execute_command(char *command)
{
	size_t i = 0;

	/* an array of instruction_t struct with opcode-function pairs */
	instruction_t instructions[] = {
		{"push", push_to_stack}, {"pall", pall}, {"pint", pint}, {"pop", pop},
		{"swap", swap}, {"add", add}, {"sub", sub}, {"div", div_op}, {"mul", mul_op},
		{"mod", mod_op}, {"pchar", pchar_op}, {"pstr", pstr_op}, {"rotl", rotl},
		{"rotr", rotr}
	};
	/* Loop through the instructions array to find a matching opcode */
	while (instructions[i].opcode != NULL)
	{
		/* Tokenize the command to get the opcode */
		monty.opcode = strtok(command, " \t\n");
		if ((monty.opcode != NULL) && IS_STACK_OR_QUEUE(monty.opcode))
		{
			/* Set the data structure type based on the opcode */
			monty.data_structure = SET_DATA_STRUCTURE(monty.opcode);
			return;
		}
		/* Check if the opcode matches the current instruction */
		if (strcmp(instructions[i].opcode, monty.opcode) == 0)
		{
			/* If the opcode is "push," get the data argument */
			if (strcmp(monty.opcode, "push") == 0)
				monty.data = strtok(NULL, " \t\n");
			/* Call the corresponding function for the opcode */
			instructions[i].f(&monty.head, monty.line_number);
			return;
		}
		i++;
	}
	/* Handle the case where the opcode is not recognized */
	if (instructions[i].opcode == NULL)
	{
		fprintf(stderr, "L%u: unknown instruction %s\n", monty.line_number,
		monty.opcode);
		exit(EXIT_FAILURE);
	}
}

/**
 * push_to_stack - Pushes an integer onto the stack.
 *
 * @stack: Double pointer to the top of the stack.
 * @line_number: Line number where the operation is called.
 */
void push_to_stack(stack_t **stack, unsigned int line_number)
{
	if (monty.data == NULL || is_integer(monty.data) == 0)
	{
		fprintf(stderr, "L%u: usage: push integer\n", line_number);
		exit(EXIT_FAILURE);
	}

	push(stack, atoi(monty.data));
}

/**
 * is_integer - Checks if a string represent a valid integer.
 *
 * @str: Input string to be checked.
 *
 * Return: 1 if the string is a valid integer, 0 otherwise.
 */
int is_integer(const char *str)
{
	if (str == NULL || *str == '\0')
	{
		return (0);
	}

	while (*str != '\0')
	{
		if (!isdigit(*str) && *str != '+' && *str != '-')
			return (0);
		str++;
	}

	return (1);
}
