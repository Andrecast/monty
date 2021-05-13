#include "monty.h"
/**
 * _push - function that adds a new node at the beginning of a list
 * @stack: pointer to the stack pointer of the list
 * @n: data in new node
 * Return: the address of the new element, or NULL if it failed
 * Description: function that adds a new node at the beginning of a list
 */
void _push(stack_t **stack, unsigned int line_number)
{
	stack_t *new;

	if (stack == NULL)/*si el doble puntero es NULL, no hay nada*/
		exit(1);
	new = malloc(sizeof(stack_t));
	/*verificar malloc**/
	if (new == NULL)
		exit(1);
	new->prev = NULL;/*le asigno NULL porq va a ser el nuevo nodo*/
	new->n = line_number;/*le asigno el número que va a llevar*/

	new->next = *stack;

	/*Mientras la lista no esté vacía*/
	if (*stack != NULL)
		(*stack)->prev = new;/*Ahora new está al inicio de la lista*/

	*stack = new;
}

/**
 * _pall -  prints all the values on the stack, starting from the top of the stack
 * @stack: pointer to the stack pointer of the list
 * @line_number: int at command input
 * Return: Nothing
 */
void _pall(stack_t **stack, __attribute__((unused))unsigned int line_number)
{
    stack_t *tmp = *stack;

    while (tmp !=   NULL)
    {
        printf("%d\n", tmp->n);
        tmp = tmp->next;
    }
}