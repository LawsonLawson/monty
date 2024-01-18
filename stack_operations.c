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
		exit(EXIT_FAILURE);
	}

	new_node->n = data;
	new_node->prev = NULL;
	new_node->next = NULL;

	if (list_empty(monty))
	{
		*stack = new_node;
		monty.tail = *stack;
	}
	else
	{
		if (monty.data_structure == GO_STACK || monty.data_structure == GO_DEFAULT)
		{
			new_node->next = *stack;
			(*stack)->prev = new_node;
			if ((*stack)->next == NULL)
				(*stack)->prev = new_node;
			*stack = new_node;
		}
		else
		{
			monty.tail->next = new_node;
			new_node->prev = monty.tail;
			monty.tail = new_node;
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
