#include "monty.h"

/**
 * swap - swaps the top two elements of the stack
 * @top: double pointer to the top of the stack
 * @line_number: line number of the file
 */
void swap(stack_t **top, unsigned int line_number)
{
    stack_t *first, *second;

    if (*top == NULL || (*top)->next == NULL)
    {
        fprintf(stderr, "L%u: can't swap, stack too short\n", line_number);
        exit(EXIT_FAILURE);
    }

    first = *top;
    second = first->next;

    first->next = second->next;
    second->prev = NULL;

    if (first->next != NULL)
        first->next->prev = first;

    second->next = first;
    first->prev = second;

    *top = second;
}

