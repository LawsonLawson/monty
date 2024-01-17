#ifndef MONTY_H
#define MONTY_H

#include <stdio.h>
#include <stdlib.h>

#define BUFFER_SIZE 1024
#define GO_DEFAULT 0
#define GO_STACK 1
#define GO_QUEUE 2


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
 * @size: Represents the number of elements in the list.
 * @destroy: A function pointer to a function that can destroy elements of the list.
 * @filename: A string representing the filename associated with the list.
 * @opcode: A string representing an operation code.
 * @buffer: A string buffer for storing data.
 * @ln_number: A pointer to an unsigned int representing line numbers.
 * @file_pointer: A pointer to a FILE structure for file operations.
 */
typedef struct list_t
{
	stack_t *head;
	stack_t *tail;
	size_t size;
	char *filename;
	char *opcode;
	char *buffer;
	char *data;
	int data_structure;
	unsigned int line_number;
	FILE *file_pointer;
	void (*destroy)(void **);
} list;

/* Declare an instance of the list structure named monty */
extern list monty;

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


/* function macros */
#define IS_STACK_OR_QUEUE(opcode) \
	(strcmp((opcode), "stack") == 0 || strcmp((opcode), "queue") == 0)
#define SET_DATA_STRUCTURE(opcode) \
	((IS_STACK_OR_QUEUE(opcode)) ? \
	 ((strcmp((opcode), "stack") == 0) ? GO_STACK : GO_QUEUE) : GO_DEFAULT)


/* parser and command exec. functions */
void parse_input();
void execute_command(char *command);

/* Memory handling functions */
void *_calloc(unsigned int nmemb, unsigned int size);
void _free(void **ptr);


#endif /* MONTY_H */
