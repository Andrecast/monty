#include "monty.h"
/**
 * read_textfile - prints it to the POSIX standard output.
 * @filename: file name.
 * @letters: number of characters.
 * Return: characters prints.
 */
ssize_t read_textfile(const char *filename, size_t letters)
{
	int _open, _read, i;
	char *ptr;
	char **tokens, **op_code;

	if (filename == NULL)
	{
		return (0);
	}

	ptr = malloc(sizeof(char) * letters);
	if (ptr == NULL)
	{
		return (0);
	}
	_open = open(filename, O_RDONLY);
	if (_open == -1)
	{
		free(ptr);
		return (0);
	}
	_read = read(_open, ptr, letters);
	if (_read == -1)
	{
		free(ptr);
		return (0);
	}
	tokens = tock_arg(ptr);
	while (!tokens)
	{
		op_code = tock_2(tokens[i]);
		printf("%s", op_code[0]);
		printf("%s", op_code[1]);
	}

	printf("%s\n", tokens[3]);
	/*printf("%s\n", tokens[1]);*/
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

    number_arg = count_w(buff_arg);
    arg_token = malloc(sizeof(char *) * (number_arg + 1));

    arg_token[pos] = strdup(strtok(buff_arg, "\n"));
    pos++;
    while (pos < number_arg - 1)
    {
        arg_token[pos] = strdup(strtok(NULL, "\n"));
        pos++;
    }
    arg_token[pos] = NULL;
    return (arg_token);
}
/**
 * tock_arg - tokenizar line of argument.
 * @buff_arg: line of argument.
 * Return: return char double pointer of tokens.
 */
char **tock_2(char *buff_arg)
{
    int number_arg = 0, pos = 0;
    char **arg_token = NULL;

    number_arg = count_2(buff_arg);
    arg_token = malloc(sizeof(char *) * (number_arg + 1));

    arg_token[pos] = strdup(strtok(buff_arg, " \t"));
    pos++;
    while (pos < number_arg - 1)
    {
        arg_token[pos] = strdup(strtok(NULL, " \t"));
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
	int step = 0, i = 0;
	unsigned int words = 0;

	while (buff[i])
	{
		if (buff[i] == '\n')
			step = 0;
		else if (step == 0)
		{
			step = 1;
			words++;
		}
		i++;
	}
	return (words);
}
/**
 * count_w - Function that counts the words writed in terminal
 * @buff: to temporarily store the words
 * Return: the number of words
 */
int count_2(char *buff)
{
	int step = 0, i = 0;
	unsigned int words = 0;

	while (buff[i])
	{
		if (buff[i] == ' ')
			step = 0;
		else if (step == 0)
		{
			step = 1;
			words++;
		}
		i++;
	}
	return (words);
}
