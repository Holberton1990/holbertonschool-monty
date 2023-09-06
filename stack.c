#include "monty.h"
/* 
 * _push - OpCode Push that pushes an element to the stack.
 * @*top: Pointer to the head of the stack.
 * _pall: Print all
 */
int value;

void _push(stack_t **top, unsigned int line_number)
{
    stack_t *new = malloc(sizeof(stack_t));
    if (new == NULL)
    {
        fprintf(stderr, "Error: malloc failed\n");
        exit(EXIT_FAILURE);
    }

    new->n = value;
    new->prev = NULL;

    if (*top == NULL)
    {
        new->next = NULL;
        *top = new;
    }
    else
    {
        new->next = *top;
        (*top)->prev = new;
        *top = new;
    }
}

void _pall(stack_t **top, unsigned int line_number)
{
    stack_t *tmp = *top;
    while (tmp != NULL)
    {
        printf("%d\n", tmp->n);
        tmp = tmp->next;
    }
}
