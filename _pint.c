#include "monty.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * _pint - prints the value at the top of the stack
 * @top: double pointer to header (top) of the stack.
 * @line_number: counter for line number of the file.
 * Return: void.
 */
void _pint(stack_t **top, unsigned int line_number)
{

	if (*top == NULL)
{
    fprintf(stderr, "L%d: can't pint, stack empty\n", line_number);
    exit(EXIT_FAILURE);
}

	printf("%d\n", (*top)->n);
}

