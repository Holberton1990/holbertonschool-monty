#include "monty.h"

/**
 * add - adds the top two elements of the stack
 * @top: double pointer to the top of the stack
 * @line_number: line number of the file
 */
void add(stack_t **top, unsigned int line_number)
{
    if (*top == NULL || (*top)->next == NULL)
    {
        fprintf(stderr, "L%u: can't add, stack too short\n", line_number);
        exit(EXIT_FAILURE);
    }

    (*top)->next->n += (*top)->n; 
    pop(top, line_number); 
}

