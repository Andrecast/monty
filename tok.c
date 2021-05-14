#include "monty.h"
/**
 * tock_arg - tokenizar line of argument.
 * @buff_arg: line of argument.
 * Return: return char double pointer of tokens.
 */

char **tock_2(char *buff_arg)
{
    int number_arg, pos = 0;
    char **arg_token = NULL;
    number_arg = count_2(buff_arg, " ");
    if (number_arg == 0)
    {
        return (NULL);
    }
    arg_token = malloc(sizeof(char *) * (number_arg + 1));
	if (!arg_token)
	{
	    return (0);
	}

    arg_token[pos] = strdup(strtok(buff_arg, "\t "));
    pos++;
    while (pos < number_arg)
    {
        arg_token[pos] = strdup(strtok(NULL, "\t "));
        pos++;
    }
    arg_token[pos] = NULL;
    return (arg_token);
}

/**
 * count_w - Function that counts the words writed in terminal
 * @buff: to temporarily store the words
 * Return: the number of words
 */

int count_2(char *buff, char *id)
{
    int i = 0;
    char *copy = strdup(buff);
    char *token = NULL;

    token = strtok(copy, id);
    while (token != NULL)
    {
        i++;
        token = strtok(NULL, id);
    }
    free(copy);
    return (i);
}
