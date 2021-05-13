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
        return (NULL);
    new = malloc(sizeof(stack_t));
    /*verificar malloc**/
    if (new == NULL)
        return (NULL);
    new->prev = NULL;/*le asigno NULL porq va a ser el nuevo nodo*/
    new->n = line_number;/*le asigno el número que va a llevar*/

    new->next = *stack;

    /*Mientras la lista no esté vacía*/
    if (*stack != NULL)
        (*stack)->prev = new;/*Ahora new está al inicio de la lista*/

    *stack = new;
    return (new);
}
/** pall -  prints all the values on the stack, starting from the top of the stack
 stack: pointer to the stack pointer of the list
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
/*imprime el primer elemento de la lista*/
void _pint(stack_t **stack, unsigned int line_number)
{
  stack_t *tmp;
  
  if (*stack == NULL)
    return (NULL);
  tmp = *stack;
  printf("%d\n", tmp->n);
}
/*elimina el primer  elemento de la lista*/
void _pop(stack_t **stack, unsigned int line_number)
{
  stack_t *tmp;
  
  if (*stack == NULL)
    return (NULL);
  tmp = *stack;
  tmp = tmp->next;
  *stack = tmp;
  free(tmp->prev);
  tmp->prev = NULL;
}
/*intercambia los dos primeros elementos de la lista*/
void _swap(stack_t **stack, unsigned int line_number)
{
  int elements = 0;
  stack_t *tmp;
  
  if(*stack == NULL)
    return ("error");
  elements++;
  tmp = *stack;
  while (tmp->next)
  {
    elements++;
    tmp = tmp->next;
  }
  if (elements < 2)
    return ("error");
  elements = tmp->n;
  tmp->n = tmp->prev->n;
  tmp->prev->n = elements;
}
/**suma los dos primeros elementos y los pone en la segunda posición*/
void _add(stack_t **stack, unsigned int line_number)
{
  int elements = 0;
  stack_t *tmp;
  
  if(*stack == NULL)
    return ("error");
  elements++;
  tmp = *stack;
  while (tmp->next)
  {
    elements++;
    tmp = tmp->next;
  }
  if (elements < 2)
    return ("error");
  tmp->prev->n = tmp->prev->n + tmp->n;
  _pop(stack, 0);
}
