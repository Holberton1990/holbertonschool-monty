#include "monty.h"

/**
 * main - Entry point for the Monty language interpreter
 * @argc: The number of command-line arguments (including the program name).
 * @argv: An array of strings containing the command-line arguments.
 * Return: Always 0 on success.
 */
int main(int argc, char *argv[])
{
    stack_t *my_stack = NULL;
    FILE *monty_file;
    char *line = NULL;
    size_t len = 0;
    ssize_t read;
    unsigned int line_number = 0;

    if (argc != 2)
    {
        fprintf(stderr, "USAGE: monty file\n");
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
            continue;

        execute_instruction(token, &my_stack, line_number);
    }

    free_stack(&my_stack);
    fclose(monty_file);
    free(line);

    return (EXIT_SUCCESS);
}
