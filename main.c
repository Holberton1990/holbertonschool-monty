#include "monty.h"

/**
 * main - Entry point for the Monty language interpreter
 * @argc: The number of command-line arguments (including the program name).
 * @argv: An array of strings containing the command-line arguments.
 * Return: Always 0 on success.
 */
int main(int argc, char *argv[])
{
    FILE *monty_file;
    char *line = NULL;
    size_t len = 0;
    ssize_t read;
    stack_t *stack = NULL;
    unsigned int line_number = 0;

    if (argc != 2)
    {
        fprintf(stderr, "Usage: %s <file>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    monty_file = fopen(argv[1], "r");
    if (monty_file == NULL)
    {
        fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
        exit(EXIT_FAILURE);
    }

    while ((read = getline(&line, &len, monty_file)) != -1)
    {
        line_number++;
        char *token = strtok(line, " \t\n");
        if (token == NULL || *token == '#')
            continue; // Empty line or comment

        void (*op_func)(stack_t **, unsigned int) = get_op(token);
        if (op_func == NULL)
        {
            fprintf(stderr, "L%u: unknown instruction %s\n", line_number, token);
            free_stack(&stack);
            fclose(monty_file);
            free(line);
            exit(EXIT_FAILURE);
        }

        // Execute the opcode function
        op_func(&stack, line_number);
    }

    // Clean up and close the file
    free_stack(&stack);
    fclose(monty_file);
    free(line);

    return (EXIT_SUCCESS);
}

