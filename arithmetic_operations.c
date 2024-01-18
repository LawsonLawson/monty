#include "monty.h"

/**
 * add - Adds the top two elements of the stack.
 *
 * @stack: A pointer to the head of the stack.
 * @line_number: The line number of the intruction in the Monty file.
 *
 * Description: This function adds the top two elements of the stack. If the
 * stack contains less than two elements, it prints and error message and exits
 * with EXIT_FAILUR. The result is stored in the second to top element of the
 * stack, and the top element is removed.
 */
void add(stack_t **stack, unsigned int line_number)
{
	if (list_size(monty) < 2)
	{
		fprintf(stderr, "L%u: can't add, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	(*stack)->next->n += (*stack)->n;
	pop(stack, line_number);/* Remove the top element */
}

/**
 * sub - Subtracts the top element of the stack form the second top element.
 *
 * @stack: A pointer to the head of the stack.
 * @line_number: The line of the instructon in the Monty file.
 *
 * Description: This function subtracts the top element of the stack from
 * the second top element. If the stack contains less than two elements,
 * it prints an error message and exits with EXIT_FAILURE. The result is
 * stored in the second top element of the stack, and the element is removed.
 */
void sub(stack_t **stack, unsigned int line_number)
{
	if (list_size(monty) < 2)
	{
		fprintf(stderr, "L%u: can't sub, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	(*stack)->next->n -= (*stack)->n;
	pop(stack, line_number);/* Remove the top element */
}

/**
 * div_op - Divides the second top element of the stack by the top element.
 *
 * @stack: A pointer to the head of the stack.
 * @line_number: The line number of instruction in the Monty file.
 *
 * Description: This function divides the second element of the stack by the
 * top element. If the stack contains less than two elements, it prints an
 * error message and exits with EXIT_FAILURE. The result is stored in the
 * second top element of the stack, and the top element is removed.
 */
void div_op(stack_t **stack, unsigned int line_number)
{
	if (list_size(monty) < 2)
	{
		fprintf(stderr, "L%u: can't div, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	if ((*stack)->n == 0)
	{
		fprintf(stderr, "L%u: division by zero\n", line_number);
		exit(EXIT_FAILURE);
	}

	(*stack)->next->n /= (*stack)->n;
	pop(stack, line_number);/* Remove the top element */
}

/**
 * mul_op - Multiplies the second top element of the stack by the top element.
 *
 * @stack: A pointer to the head of the stack.
 * @line_number: The line number of the instruction in the Monty file.
 *
 * Description: This function multiplies the second top element of the stack by
 * the top element. If the stack contains less than two elements, it prints an
 * error message and exits with EXIT_FAILURE. The result is stored in the
 * second top element of the stack and the top element is removed.
 */
void mul_op(stack_t **stack, unsigned int line_number)
{
	if (list_size(monty) < 2)
	{
		fprintf(stderr, "L%u: can't mul, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	(*stack)->next->n *= (*stack)->n;
	pop(stack, line_number);/* Remove the top element */
}

/**
 * mod_op - Computes the rest of the division of the second top element
 * of the stack by the top element.
 *
 * @stack: A pointer to the head of the stack.
 * @line_number: The line of the intruction in the Monty file.
 *
 * Description: This function computes the rest of the division of the second
 * top element of the stack by the top element. If the stack contains less
 * than two elements, it prints an error message and exits with EXIT_FAILURE.
 * If the top element of the stack is 0, it prints and error message and exits
 * with EXIT_FAILURE. The result is stored in the second top element of the
 * stack, and the top element is removed.
 */
void mod_op(stack_t **stack, unsigned int line_number)
{
	if (list_size(monty) < 2)
	{
		fprintf(stderr, "L%u: can't mod, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	if ((*stack)->n == 0)
	{
		fprintf(stderr, "L%u: division by zero\n", line_number);
		exit(EXIT_FAILURE);
	}

	(*stack)->next->n %= (*stack)->n;
	pop(stack, line_number);/* Remove the top element */
}
