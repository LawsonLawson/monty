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
