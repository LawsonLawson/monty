#include "monty.h"

/**
 * _putchar - prints characters passed into it unto the screen
 * @c: Characters this function prints
 *
 * Return: 1 (Success)
 */
int _putchar(char c)
{
	return (write(1, &c, 1));
}
/**
 * pchar_op - Prints the characters at the top of the stack.
 *
 * @stack: A pointer to the head of the stack.
 * @line_number: The line number of the instruction in the Monty file.
 *
 * Description: This function prints the character at the top of the stack,
 * followed by a new line. The interger stored at the top of the stack is
 * treated as the ASCII value of the character to be printed. If the value
 * is not in the ASCII table, it prints error message and exits with
 * EXIT_FAILURE.
 */
void pchar_op(stack_t **stack, unsigned int line_number)
{
	int ascii_value;

	if (list_empty(monty))
	{
		fprintf(stderr, "L%u: can't pchar, stack empty\n", line_number);
		exit(EXIT_FAILURE);
	}

	ascii_value = (*stack)->n;
	if (ascii_value < 0 || ascii_value > 127)
	{
		fprintf(stderr, "L%u: can't pchar, value out of range\n", line_number);
		exit(EXIT_FAILURE);
	}

	_putchar(ascii_value);
	_putchar('\n');
}

/**
 * pstr_op - Prints the string starting at the top of the stack.
 *
 * @stack: A pointer to the head of the stack.
 * @line_number: The line of the instruction in the Monty file.
 *
 * Description: This function prints string starting at the top of the stack,
 * followed by a new line. The integer in each element of the stack is treated
 * as the ASCII value of the character to be printed. The string stops when
 * either:
 * - the stack is empty.
 * - the value of the element is 0
 * - the value of the element is not in the ASCII table
 * If the stack is empty, only a new line gets printed.
 */
void pstr_op(stack_t **stack, unsigned int line_number)
{
	stack_t *current = *stack;

	while (current != NULL && current->n != 0 &&
	(current->n >= 0 && current->n <= 127))
	{
		_putchar(current->n);
		current = current->next;
	}
	_putchar('\n');
	(void)line_number;/* perhaps __unused__ att would surfice */
}

/**
 * nop - Does not do anything.
 *
 * @staack: A pointer to the head of the stack.
 * @line_number: The line number of instruction in the Monry file.
 *
 * Description: This function doesn't perform any operation unlike the others.
 * It takes the stack and line number parameters, but it does not modify the
 * stack ofr perform any other action on it.
 */
void nop(stack_t **stack, unsigned int line_number)
{
	(void)stack;
	(void)line_number;
}
