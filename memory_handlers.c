#include "monty.h"

/**
 * _calloc - allocates memory dynamically
 *
 * @nmemb: number of elements
 * @size: number of bytes to allocate
 *
 * Descrption: The _calloc() function allocates memory for an array of @nmemb
 * elements of @size bytes each and returns a pointer to the allocated memory.
 * The memory is set to zero. If nmemb or size is 0, then _calloc() returns
 * NULL
 *
 * Return: pointer to the allocated memory, NULL on failure.
 */

void *_calloc(unsigned int nmemb, unsigned int size)
{
	char *mem;
	unsigned int i;
	size_t totalMemory;

	if (nmemb == 0 || size == 0)
	{
		return (NULL);
	}

	totalMemory = size * nmemb;
	mem = malloc(totalMemory);
	if (mem == NULL)
	{
		return (NULL); /* memory alloc. failed */
	}

	i = 0;
	while (i < totalMemory)
	{
		mem[i] = 0; /* set memory to 0 */
		++i;
	}

	return (mem);
}

/**
 * _free - Frees/deallocates a pointer/dynamically allocated memory
 * and sets it to NULL.
 *
 * @ptr: A pointer to the pointer to be freed.
 *
 * Description: This function takes a pointer to a pointer and
 * frees the memory it points to, then sets the original pointer to
 * NULL to avoid dangling pointers.
 *
 * Note: explicitly cast the pointer type to void when you call `_free`.
 */
void _free(void **ptr)
{
	if (ptr != NULL && *ptr != NULL)
	{
		free(*ptr);
		*ptr = NULL;
	}
}

/**
 * free_stack - Frees all nodes in the stack.
 * @stack: A pointer to the head of the stack.
 *
 * Description:
 *   This function frees all nodes in the stack, one by one,
 *   by repeatedly calling the `pop` function.
 *   It continues until the stack is empty or the provided
 *   stackpointer is NULL. The line number is used for error
 *   reporting in the `pop` function.
 */
void free_stack(stack_t **stack)
{
	while (stack != NULL && *stack != NULL)
	{
		pop(stack, monty.line_number);
	}
}

 /**
 * exit_gracefully - Performs cleanup tasks before exiting the program.
 *
 * Description:
 *   This function is responsible for performing cleanup tasks
 *   before exiting the program in case of an error or 
 *   abnormal termination. It deallocates memory for the buffer,
 *   frees the entire stack, closes the file pointer,
 *   and then exits the program with a failure status.
 */
void exit_gracefully(void)
{
	/* destroy the buffer */
	monty.destroy((void **)&monty.buffer);

	free_stack(&monty.head);

	/* close the file pointer */
	if (monty.file_pointer != NULL)
		fclose(monty.file_pointer);

	exit(EXIT_FAILURE);
}
