#include "monty.h"
/**
 * pop - removes the top element of the stack
 * @top: double pointer to the top of the stack
 * @line_number: line number of the file
 */
void _pop(stack_t **top, unsigned int line_number)
{
	stack_t *temp;

	if (*top == NULL)
	{
        fprintf(stderr, "L%u: can't pop an empty stack\n", line_number);
        exit(EXIT_FAILURE);
    }
	temp = *top;
	*top = (*top)->next;

    if (*top != NULL)
        (*top)->prev = NULL;

    free(temp);
}
