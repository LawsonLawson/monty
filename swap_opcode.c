#include "monty.h"

/**
 * swap - Swaps the top two elements of the stack.
 *
 * @stack: A pointer to the head of the stack.
 * @line_number: The liine number of the intruction in the Monry file.
 *
 * Description: This function swaps the top two elements of the stack. If the
 * stack contains less than two elements, it prints an error message and
 * exits with EXIT_FAILURE.
 */
void swap(stack_t **stack, unsigned int line_number)
{
	int temp;

	if (list_size(monty) < 2)
	{
		fprintf(stderr, "L%u: can't swap, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	temp = (*stack)->n;
	(*stack)->n = (*stack)->next->n;
	(*stack)->next->n = temp;
}
