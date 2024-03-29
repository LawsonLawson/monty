#include "monty.h"

/**
 * push - Adds a new node with the given data to the stack or queue.
 * @stack: A pointer to the head of the stack or queue.
 * @data: The data to be stored in the new node.
 *
 * Description:
 *   This function creates a new node with the provided data and inserts it
 *   either at the top of the stack or at the end of the queue based on the
 *   current data structure type. It handles memory allocation errors and
 *   updates the size of the list accordingly.
 */
void push(stack_t **stack, int data)
{
	stack_t *new_node = malloc(sizeof(stack_t));

	if (new_node == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit_gracefully();
	}

	new_node->n = data;
	new_node->prev = NULL;

	if (list_empty(monty))
	{
		*stack = new_node;
		(*stack)->next = NULL;
		monty.tail = *stack;
	}
	else
	{
		if (monty.data_structure == GO_QUEUE)
		{
			monty.tail->next = new_node;
			new_node->prev = monty.tail;
			monty.tail = new_node;
		}
		else
		{
			new_node->next = *stack;
			(*stack)->prev = new_node;
			if ((*stack)->next == NULL)
				(*stack)->prev = new_node;

			*stack = new_node;
		}
	}
	monty.size++;
}

/**
 * pall - Prints all elements in the stack.
 *
 * @stack: Double pointer to the top of the stack.
 * @line_number: Line number where the operation is called (unused).
 */
void pall(stack_t **stack, __attribute__((unused)) unsigned int line_number)
{
	stack_t *current = NULL;

	if (list_empty(monty))
	{
		return; /* list empty, return */
	}

	current = *stack;
	while (current != NULL)
	{
		printf("%d\n", current->n);
		current = current->next;
	}

	fflush(stdout);
}

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
		fprintf(stderr, "L%u: can't pint, stack empty\n", line_number);
		exit_gracefully();
	}

	printf("%d\n", (*stack)->n);
}

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
		fprintf(stderr, "L%u: can't pop an empty stack\n", line_number);
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
