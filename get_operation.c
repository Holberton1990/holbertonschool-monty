#include <stdio.h>
#include <stdlib.h>
#include "monty.h"

int main(int argc, char **argv)
{
	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}

	FILE *file = fopen(argv[1], "r");
	if (file == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}

	initialize_stack(&stack);

	char *line = NULL;
	size_t len = 0;
	unsigned int line_number = 0;
	char *opcode;

	while (getline(&line, &len, file) != -1)
	{
		line_number++;
		opcode = strtok(line, " \t\n");
		if (opcode != NULL && opcode[0] != '#')
		{
			execute_instruction(opcode, &stack, line_number);
		}
	}
	free(line);
	fclose(file);
	free_stack(&stack);
	return (0);
}

