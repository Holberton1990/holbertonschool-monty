#include "monty.h"
/* 
 * _push - OpCode Push that pushes an element to the stack.
 * @*top: Pointer to the head of the stack.
 * _pall: Print all
 */
int value;

/**
 * _push - Opcode Push that pushes an element to the stack.
 * @top: Pointer to the head of the stack.
 * @line_number: Line number in the file.
 */
void _push(stack_t **top, unsigned int line_number)
{
    char *arg = strtok(NULL, " \t\n"); // Get the argument after "push"
    
    if (!arg || !is_numeric(arg))
    {
        fprintf(stderr, "L%u: usage: push integer\n", line_number);  // Updated error message format
        exit(EXIT_FAILURE);
    }
    
    int value = atoi(arg);
    
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


void _pall(stack_t **top, unsigned int __attribute__((unused)) line_number) 
{
    stack_t *tmp = *top;
    while (tmp != NULL)
    {
        printf("%d\n", tmp->n);
        tmp = tmp->next;
    }
}

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

/**
 * swap - swaps the top two elements of the stack
 * @top: double pointer to the top of the stack
 * @line_number: line number of the file
 */
void _swap(stack_t **top, unsigned int line_number)
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

/**
 * add - adds the top two elements of the stack
 * @top: double pointer to the top of the stack
 * @line_number: line number of the file
 */
void _add(stack_t **top, unsigned int line_number)
{
    if (*top == NULL || (*top)->next == NULL)
    {
        fprintf(stderr, "L%u: can't add, stack too short\n", line_number);
        exit(EXIT_FAILURE);
    }

    (*top)->next->n += (*top)->n;
    _pop(top, line_number);
}

/**
 * nop - doesn't do anything
 * @top: double pointer to the top of the stack
 * @line_number: line number of the file
 */
void _nop(stack_t **top, unsigned int line_number)
{
    (void)top;
    (void)line_number;
    /* This function does nothing */
}
int is_numeric(const char *str)
{
    if (str == NULL || *str == '\0')
        return 0; // Not numeric

    for (int i = 0; str[i] != '\0'; i++)
    {
        if (!isdigit((unsigned char)str[i]))
            return 0; // Not numeric
    }

    return 1; // Numeric
}
/**
 * free_stack - Frees all nodes in the stack.
 * @stack: A pointer to the head of the stack.
 */
void free_stack(stack_t **stack)
{
    stack_t *current = *stack;
    stack_t *temp;

    while (current != NULL)
    {
        temp = current;
        current = current->next;
        free(temp);
    }

    *stack = NULL; // Set the stack pointer to NULL to indicate an empty stack.
}

