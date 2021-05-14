#include "monty.h"

void funtions(char *words, stack_t **stack, unsigned int line_number)
{
	int i = 0;

	instruction_t op [] = {
		{"push", _push},
		{"pall", _pall},
		{"pint", _pint},
		{"pop", _pop},
		{"swap", _swap},
		{"add", _add},
		{NULL, NULL}
	};
	for (i = 0; op[i].opcode != NULL; i++)
	{
		if (strcmp(words, op[i].opcode) == 0)
		{
			op[i].f(stack, line_number);
			break;
		}
	}

	if (op[i].opcode == NULL)
	{
		dprintf(2, "L<line_number>: unknown instruction %s\n", words);
	}
}
