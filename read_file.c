#include "monty.h"
/**
 * read_textfile - prints it to the POSIX standard output.
 * @filename: file name.
 * @letters: number of characters.
 * Return: characters prints.
 */
int read_textfile(const char *filename, size_t letters)
{
    int _open, _read, i = 0;
    char *ptr = NULL;
    char **tokens = NULL, **arg = NULL;

    if (filename == NULL)
    {
        dprintf(2, "Error: Can't open file %s\n", filename);
        exit(1);
    }

    ptr = malloc(sizeof(char) * letters);
    if (ptr == NULL)
    {
        return (0);
    }

    _open = open(filename, O_RDONLY);
    if (_open == -1)
    {
        dprintf(2, "Error: Can't open file %s\n", filename);
        free(ptr);
        exit(1);
    }
    _read = read(_open, ptr, letters);
    if (_read == -1 || _read == 0)
    {
        dprintf(2, "Error: Can't open file %s\n", filename);
        exit(1);
    }
    tokens = tock_arg(ptr);

	while (tokens[i] != NULL)
	{
        printf("%s tokens \n", tokens[i]);
		arg = tock_2(tokens[i]);
        valor = arg[1];
        if (arg == NULL)
        {
            perror ("No hay argumentos");
            i++;
            continue;
        }
        /*if (arg != NULL)
        {
            printf("%s Seg token pos 0\n", arg[0]);
        }*/
		free_dpointer(arg);
		i++;
	}
    /*printf("%s\n", tokens[1]);*/
	free_dpointer(tokens);
    free(ptr);
    close(_open);
    return (0);
}

/**
 * tock_arg - tokenizar line of argument.
 * @buff_arg: line of argument.
 * Return: return char double pointer of tokens.
 */

char **tock_arg(char *buff_arg)
{
    int number_arg = 0, pos = 0;
    char **arg_token = NULL;

    number_arg = count_2(buff_arg,"\n");
    arg_token = malloc(sizeof(char *) * (number_arg + 1));
	if (!arg_token)
	{
		return (NULL);
	}
	
    arg_token[pos] = strdup(strtok(buff_arg, "\n"));
    pos++;
    while (pos < number_arg)
    {
        arg_token[pos] = strdup(strtok(NULL, "\n"));
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

int count_w(char *buff)
{
    int words = 0;
	int i = 0;

    while (buff[i])
    {
        if (buff[i] == '\n')
            words++;
        i++;
    }
    printf("%d este es words\n", words);
    return (words);
}

int free_dpointer(char **pointer)
{
	int i = 0;

	while (pointer[i] != NULL)
	{
		free(pointer[i]);
		i++;
	}
	free(pointer);
    return(0);
}