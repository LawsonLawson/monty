#ifndef MONTY_H
#define MONTY_H

/**
 * struct stack_s - Doubly likned list representation of a stack (or queue)
 * @n: integer.
 * @prev: points to the previous element of the stack (or queue)
 * @next: points tot the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO
 */
typedef struct stack_s
{
	int n;
	struct stack_s *prev;
	struct stack_s *next;
} stack_t;

/**
 * struct list_t - Represents a list with head and tail pointers.
 *
 * @head: Points to the first element of the list.
 * @tail: Points to the last element of the list.
 */
typedef struct list_t
{
	stack_t *head;
	stack_t *tail;
} list;

/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO
 */
typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

#endif /* MONTY_H */
