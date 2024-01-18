#include "monty.h"
/**
 * pop - Removes the top element of the stack.
 *
 * @stack: A pointer to the head of the stack.
 * @line_number: The line number of the intruction in the Monry file.
 *
 * Description: This function removes the top element of the stack if the stack
 * is not empty. If the stack is empty, it prints an erroe message and exits
 * with EXIT_FAILURE.
 */
void pop(stack_t **stack, unsigned int line_number)
{
	stack_t *temp;

	if (list_empty(monty))
	{
		fprintf(stderr, "L%u: can't pop and empty stack\n", line_number);
		exit(EXIT_FAILURE);
	}
	temp = *stack;

	if (temp->next != NULL)
	{
		*stack = temp->next;
		(*stack)->prev = NULL;
	}
	else
	{
		*stack = NULL;
		monty.tail = NULL;
	}

	free(temp);
	monty.size--;
}
