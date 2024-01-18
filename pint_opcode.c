#include "monty.h"

/**
 * pint - Prints the value at the top of the stack.
 *
 * @stack: A pointer to the head of the stack.
 * @line_number: The line in the Monty file where the pint opcode appears.
 *
 * Description: This function prints the value at the top of the stack and
 * exits with EXIT_FAILURE if the stack is empty.
 */
void pint(stack_t **stack, unsigned int line_number)
{
	if (list_empty(monty))
	{
		fprintf(stderr, "L%u: can't pint, stack empry\n", line_number);
		exit(EXIT_FAILURE);
	}

	printf("%d\n", (*stack)->n);
}
