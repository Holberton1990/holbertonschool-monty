#include "monty.h"

/**
 * monty_error - Prints an error message and exits the program
 * @msg: The error message to print
 * @line_number: The line number where the error occurred
 * @opcode: The opcode associated with the error
*/

void monty_error(char *msg, unsigned int line_number, char *opcode)
{
        fprintf(stderr, "L%u: %s %s\n", line_number, msg, opcode);
        free_stack(&stack);
        exit(EXIT_FAILURE);
}

