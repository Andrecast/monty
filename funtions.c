#include "monty.h"

/**
 * funtions - compare arguments.
 * @words: arguments.
 * @stack: head linked list.
 * @line_number: number line.
 * Return: void.
 */

void funtions(char *words, stack_t **stack, unsigned int line_number)
{
	int i = 0;

	instruction_t op[] = {
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
		dprintf(2, "L%d: unknown instruction %s\n", line_number, words);
		exit(EXIT_FAILURE);
	}
}

/**
 * _push - function that adds a new node at the beginning of a list
 * @stack: pointer to the stack pointer of the list
 * @line_number: data in new node
 * Return: the address of the new element, or NULL if it failed
 * Description: function that adds a new node at the beginning of a list
 */
void _push(stack_t **stack, unsigned int line_number)
{
	stack_t *new;
		(void)line_number;

	if (stack == NULL)/*si el doble puntero es NULL, no hay nada*/
		exit(EXIT_FAILURE);
	new = malloc(sizeof(stack_t));
	/*verificar malloc**/
	if (new == NULL)
	{
		dprintf(STDERR_FILENO, "Error: malloc failed");
		exit(EXIT_FAILURE);
	}
	new->prev = NULL;/*le asigno NULL porq va a ser el nuevo nodo*/
	new->n = value;/*le asigno el número que va a llevar*/
	new->next = *stack;
	/*Mientras la lista no esté vacía*/
	if (*stack != NULL)
		(*stack)->prev = new;/*Ahora new está al inicio de la lista*/
	*stack = new;
}
/**
 * _pall - prints all the values on the stack
 * @stack: head linked list
 * @line_number: int at command input
 * Return: Nothing
 */
void _pall(stack_t **stack, unsigned int line_number)
{
	(void)line_number;
	stack_t *tmp = *stack;

	while (tmp !=   NULL)
	{
		printf("%d\n", tmp->n);
		tmp = tmp->next;
	}
}
