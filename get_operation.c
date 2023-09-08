#include "monty.h"

/* Global variable for the stack */
stack_t *stack = NULL;

/**
 * free_stack - Frees a stack
 * @stack: Pointer to the head of the stack
 */
void free_stack(stack_t **stack)
{	
	stack_t *current, *temp;	
	if (stack == NULL || *stack == NULL)	
		return;	
	current = *stack;	
	while (current != NULL)	
{	
	temp = current;
        current = current->next;
        free(temp);
    }
}

/**
 * execute_instruction - Executes a Monty bytecode instruction
 * @opcode: The opcode to execute
 * @stack: Pointer to the head of the stack
 * @line_number: The current line number in the Monty file
 */
void execute_instruction(char *opcode, stack_t **stack, unsigned int line_number)
{	
	instruction_t instructions[] = {	
		{"push", push},	
		{"pall", pall},	
		{"pint", pint},	
		{"pop", pop},	
		{"swap", swap},	
		{"add", add},	
		{"nop", nop},	
		{NULL, NULL}	
	};	
	
	int i = 0;
	
	while (instructions[i].opcode != NULL)
{	
		if (strcmp(opcode, instructions[i].opcode) == 0)
{
            instructions[i].f(stack, line_number);
            return;
}	
		i++;
}

/**
     * If the opcode is not recognized, print an error message.
     * Description: This message indicates that the program encountered 
     * an instruction it cannot interpret or execute.	
     * monty_error - Prints an error message and exits the program
     * @msg: The error message to print
     * @line_number: The line number where the error occurred
     * @opcode: The opcode associated with the error
 */	
	    monty_error("unknown instruction", line_number, opcode);
}
	void monty_error(char *msg, unsigned int line_number, char *opcode)
{	
	fprintf(stderr, "L%u: %s %s\n", line_number, msg, opcode);	
	free_stack(&stack);	
	exit(EXIT_FAILURE);
}
