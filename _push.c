#include "monty.h"
/**
 * _push - OpCode Push that pushes an element to the stack.
 * @ptr: Pointer to the head of the stack.
 * @cnt: Count.
 */
void push(stack_t **stack, int value, unsigned int line_number) {
    // Kontrollo nëse argumenti është numër të plotë
    if (!is_integer(value)) {
        fprintf(stderr, "L%u: usage: push integer\n", line_number);
        exit(EXIT_FAILURE);
    }

    // Krijo një element të ri për stapin
    stack_t *new_node = malloc(sizeof(stack_t));
    if (!new_node) {
        fprintf(stderr, "Error: malloc failed\n");
        ultrafree(new);
	exit(EXIT_FAILURE);
    }

    // Vendos vlerën në elementin e ri
    new_node->n = value;
    new_node->next = *stack;
    new_node->prev = NULL;
    if (*stack) {
        (*stack)->prev = new_node;
    }

    // Ndrysho kryesinë e stapit
    *stack = new_node;
}
else
	{
		dprintf(stderr, "Error: malloc failed\n");
		ultrafree((*ptr));
		free(new);
		exit(EXIT_FAILURE);
	}
void pall(stack_t **stack) {
    stack_t *current = *stack;
    while (current) {
        printf("%d\n", current->n);
        current = current->next;
    }
}

