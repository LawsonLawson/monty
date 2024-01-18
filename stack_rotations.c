#include "monty.h"

/**
 * rotl - Rotates the stack to the top.
 *
 * @stack: A pointer to the head of the stack.
 * @line_number: The line number of the instruction in the Monty file.
 *
 * Description: This function rotates the stack to the top.
 * The top element becomes the last one, and the second top element becomes the
 * first one. If the stack contains less than two elements, it doesn't change
 * the stack.
 */
void rotl(stack_t **stack, __attribute__((unused)) unsigned int line_number)
{
	stack_t *temp;

	if (list_size(monty) < 2)
	{
		/* If stack contains less than 2 elements, don't change the stack. */
		return;
	}
	temp = *stack;
	/* Traverse to the last element */
	while (temp->next != NULL)
	{
		temp = temp->next;
	}
	/* Adjust pointers for rotation */
	temp->next = *stack;
	(*stack)->prev = temp;
	*stack = (*stack)->next;
	(*stack)->prev->next = NULL;/* Set new last element's next to NULL */
	(*stack)->prev = NULL;
}

/**
 * rotr - Rotates the stack to the bottom.
 * @stack: A pointer to the head of the stack.
 * @line_number: The line number of the instruction in the Monty file.
 *
 * Description:
 *   This function rotates the stack to the bottom.
 *   The last element becomes the top element, and all other elements move up.
 *   If the stack contains less than two elements, it doesn't change the stack.
 *   rotr never fails.
 */
void rotr(stack_t **stack, __attribute__((unused)) unsigned int line_number)
{
	stack_t *temp;

	if (list_size(monty) < 2)
	{
		/* If stack contains less than two elements, it doesn't change the stack. */
		return;
	}
	temp = *stack;
	/* Traverse to the last element */
	while (temp->next != NULL)
	{
		temp = temp->next;
	}

    /* Adjust pointers for rotation */
	temp->prev->next = NULL;/* Set current last element's next to NULL*/
	temp->next = *stack;
	(*stack)->prev = temp;
	*stack = temp;
	(*stack)->prev = NULL;
}
