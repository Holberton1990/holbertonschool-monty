#include "monty.h"

/**
 * _pint - prints the value at the top of the stack
 * @top: double pointer to header (top) of the stack.
 * @line_number: counter for line number of the file.
 * Return: void.
 */
void _pint(stack_t **top, unsigned int line_number)
{
	stack_t *current = *stack;

	if (*stack == NULL)
	{
		dprintf(STDERR, "L%d: can't pint, stack empty\n", line_number);

		exit(EXIT_FAILURE);
	}

	printf("%d\n", current->n);
}
