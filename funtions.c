#include "monty.h"

void (*funtions (char *words))(stack_t **stack, unsigned int line_number)
{
	instruction_t op_code[] = {
		{"push", _push},
		{"pall", _pall},
		/*{"pint", _pint},
		{"pop", _pop},
		{"swap", _swap},
		{"add", _add},*/
		{NULL, NULL}
	};
	int i = 0;

	i++;
	while (op_code[i].opcode != NULL)
	{
		if (strcmp(words, op_code[i].opcode) == 0)
		{
			return (op_code[i].f);
		}
		i++;
	}
	if (op_code[i].opcode == NULL)
	{
		dprintf(2, "L<line_number>: unknown instruction %s\n", words);
	}
	return ('\0');
}
