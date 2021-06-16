#include "monty.h"
/**
 * _pint -  prints firts value on the stack
 * @stack: head linked list
 * @line_number: int at command input
 * Return: Nothing
 */
void _pint(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp;
	(void)line_number;
	if (*stack == NULL)
		exit(EXIT_FAILURE);
	tmp = *stack;
	printf("%d\n", tmp->n);
}

/**
 * _pop -  remove firts element on the stack
 * @stack: head linked list
 * @line_number: int at command input
 * Return: Nothing
 */

void _pop(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp;
	(void)line_number;
	if (*stack == NULL)
		exit(EXIT_FAILURE);
	tmp = *stack;
	tmp = tmp->next;
	*stack = tmp;
	free(tmp->prev);
	tmp->prev = NULL;
}
/**
 * _swap -  exchanges the first two elements of the list
 * @stack: head linked list
 * @line_number: int at command input
 * Return: Nothing
 */

void _swap(stack_t **stack, unsigned int line_number)
{
	int elements = 0;
	stack_t *tmp;
	(void)line_number;

	if (*stack == NULL)
		exit(EXIT_FAILURE);
	elements++;
	tmp = *stack;
	while (tmp->next)
	{
		elements++;
		tmp = tmp->next;
	}
	if (elements < 2)
		exit(EXIT_FAILURE);
	elements = tmp->n;
	tmp->n = tmp->prev->n;
	tmp->prev->n = elements;
}
/**
 * _add -  adds the first two elements together
 * @stack: head linked list
 * @line_number: int at command input
 * Return: Nothing
 */
void _add(stack_t **stack, unsigned int line_number)
{
	int elements = 0;
	stack_t *tmp;
	(void)line_number;

	if (*stack == NULL)
		exit(EXIT_FAILURE);
	elements++;
	tmp = *stack;
	while (tmp->next)
	{
		elements++;
		tmp = tmp->next;
	}
	if (elements < 2)
		exit(EXIT_FAILURE);
	tmp->prev->n = tmp->prev->n + tmp->n;
	_pop(stack, 0);
}
