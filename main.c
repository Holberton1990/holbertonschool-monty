#include "monty.h"

/**
 * main - Monty bytecode interpreter
 * @argc: number of arguments passed
 * @argv: array of argument strings
 *
 * Return: EXIT_SUCCESS on success or EXIT_FAILURE on failure
 */
int main(int argc, char *argv[])
{
    stack_t *stack = NULL;
    unsigned int line_number = 0;
    FILE *fs = NULL;
    char *lineptr = NULL, *op = NULL;
    size_t n = 0;

    struct var_t var;
    var.queue = 0;
    var.stack_len = 0;

    if (argc != 2)
    {
        dprintf(STDOUT_FILENO, "USAGE: monty file\n");
        exit(EXIT_FAILURE);
    }

    fs = fopen(argv[1], "r");
    if (fs == NULL)
    {
        dprintf(STDOUT_FILENO, "Error: Can't open file %s\n", argv[1]);
        exit(EXIT_FAILURE);
    }

   while (getline(&lineptr,&n, fs) !=-1)
   {
        line_number++;
        op = strtok(lineptr, "\n\t\r ");
        if (op != NULL && op[0] != '#')
        {
            if (strcmp(op, "push") == 0)
            {
                op = strtok(NULL, "\n\t\r ");
                if (op == NULL || !is_numeric(op))
                {
                    fprintf(stderr, "L%u: usage: push integer\n", line_number);
                    exit(EXIT_FAILURE);
                }
                push(&stack, atoi(op));
            }
            else if (strcmp(op, "pall") == 0)
            {
                pall(stack);
            }
            else if (strcmp(op, "pop") == 0)
            {
                pop(&stack, line_number);
            }
            else if (strcmp(op, "add") == 0)
            {
                add(&stack, line_number);
            }
            else if (strcmp(op, "nop") == 0)
            {
                nop(&stack, line_number);
            }
            else if (strcmp(op, "pint") == 0)
            {
                pint(stack, line_number);
            }
            else if (strcmp(op, "swap") == 0)
            {
                swap(&stack, line_number);
            }
        
        }
    }

    fclose(fs);
    free(lineptr);

    exit(EXIT_SUCCESS);
}

