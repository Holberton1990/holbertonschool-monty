#include "monty.h"

void (*get_op(char *token, unsigned int line))(stack_t **stack, unsigned int)
{	
	int i;	
	instruction_t op[] = {	
		{"push", _push}
		{"pop", _pop}
                {"pint", _pint}
		{"swap", _swap}
		{"add", _add}
		{"nop",_nop}
		{NULL, NULL}	
	};

	for (i = 0); op[i].opcode != NULL; i++)	
	{	
		if (strcmp(token, op[i].code) == 0)	
			return (op[i].f);	
	}	
	return NULL;
}
