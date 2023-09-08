#include "monty.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * push - Pushes an element onto the stack.
 * @stack: A pointer to the stack.
 * @line_number: The line number in the Monty file.
 */
void push(stack_t **stack, unsigned int line_number)
{
    char *arg;
    int value;

    arg = strtok(NULL, " \t\n");
    if (!arg || !is_numeric(arg))
    {
        fprintf(stderr, "L%u: usage: push integer\n", line_number);
        free_stack(stack);
        exit(EXIT_FAILURE);
    }

    value = atoi(arg);
    if (push_stack(stack, value) == NULL)
    {
        fprintf(stderr, "Error: malloc failed\n");
        free_stack(stack);
        exit(EXIT_FAILURE);
    }
}
/**
 * pall - Prints all the values on the stack.
 * @stack: A pointer to the stack.
 * @line_number: The line number in the Monty file.
 */
void pall(stack_t **stack, unsigned int line_number)
{
    (void)line_number;

    if (!stack || !*stack)
        return;

    stack_t *current = *stack;
    while (current)
    {
        printf("%d\n", current->n);
        current = current->next;
    }
}
/**
 * pop - Removes the top element from the stack.
 * @stack: A pointer to the stack.
 * @line_number: The line number in the Monty file.
 */
void pop(stack_t **stack, unsigned int line_number)
{
    if (!stack || !*stack)
    {
        fprintf(stderr, "L%u: can't pop an empty stack\n", line_number);
        free_stack(stack);
        exit(EXIT_FAILURE);
    }

    stack_t *top = *stack;
    *stack = (*stack)->next;
    if (*stack)
        (*stack)->prev = NULL;
    free(top);
}
/**
 * swap - Swaps the top two elements of the stack.
 * @stack: A pointer to the stack.
 * @line_number: The line number in the Monty file.
 */
void swap(stack_t **stack, unsigned int line_number)
{
    if (!stack || !*stack || !((*stack)->next))
    {
        fprintf(stderr, "L%u: can't swap, stack too short\n", line_number);
        free_stack(stack);
        exit(EXIT_FAILURE);
    }

    stack_t *temp = (*stack)->next;
    (*stack)->next = temp->next;
    temp->next = *stack;
    temp->prev = NULL;
    (*stack)->prev = temp;
    *stack = temp;
}
/**
 * add - Adds the top two elements of the stack.
 * @stack: A pointer to the stack.
 * @line_number: The line number in the Monty file.
 */
void add(stack_t **stack, unsigned int line_number)
{
    if (!stack || !*stack || !((*stack)->next))
    {
        fprintf(stderr, "L%u: can't add, stack too short\n", line_number);
        free_stack(stack);
        exit(EXIT_FAILURE);
    }

    (*stack)->next->n += (*stack)->n;
    pop(stack, line_number);
}
/**
 * nop - Does nothing.
 * @stack: A pointer to the stack.
 * @line_number: The line number in the Monty file.
 */
void nop(stack_t **stack, unsigned int line_number)
{
    (void)stack;
    (void)line_number;
}
/**
 * pint - Prints the value at the top of the stack.
 * @stack: A pointer to the stack.
 * @line_number: The line number in the Monty file.
 */
void pint(stack_t **stack, unsigned int line_number)
{
    if (!stack || !*stack)
    {
        fprintf(stderr, "L%u: can't pint, stack empty\n", line_number);
        free_stack(stack);
        exit(EXIT_FAILURE);
    }

    printf("%d\n", (*stack)->n);
}
/**
 * is_numeric - Check if a string is a numeric integer.
 * @str: The string to check.
 *
 * Return: 1 if the string is numeric, 0 otherwise.
 */
int is_numeric(const char *str)
{
    if (!str || *str == '\0')
        return 0;

    int i = 0;

    if (str[i] == '-' || str[i] == '+')
        i++;

    for (; str[i] != '\0'; i++)
    {
        if (str[i] < '0' || str[i] > '9')
            return 0;
    }

    return 1;
}
/**
 * push_stack - Adds a new element in the beginning of stack.
 * @stack: The address of stack.
 * @n: The value added to the stack.
 *
 * Return: Pointer to the new element, or NULL if fails.
 */
stack_t *push_stack(stack_t **stack, int n)
{
    stack_t *new_node;

    new_node = malloc(sizeof(stack_t));
    if (new_node == NULL)
    {
        fprintf(stderr, "Error: malloc failed\n");
        return (NULL);
    }

    new_node->n = n;
    new_node->prev = NULL;

    if (*stack != NULL)
    {
        new_node->next = *stack;
        (*stack)->prev = new_node;
    }
    else
    {
        new_node->next = NULL;
    }

    *stack = new_node;

    return (new_node);
}
