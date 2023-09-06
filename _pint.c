#include "monty.h"

/**
 * _pint - prints the value at the top of the stack
 * @top: double pointer to header (top) of the stack.
 * @line_number: counter for line number of the file.
 * Return: void.
 */
void _pint(stack_t **top, unsigned int line_number)
{
	stack_t *current_top = *top;

	if (current_top == NULL)
{
    dprintf(STDERR_FILENO, "L%u: can't pint, stack empty\n", line_number);
    exit(EXIT_FAILURE);
}

	printf("%d\n", current_top->n);
}

