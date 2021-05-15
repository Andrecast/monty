#include "monty.h"
/**
 * read_textfile - prints it to the POSIX standard output.
 * @filename: file name.
 * @letters: number of characters.
 * Return: characters prints.
 */

char *read_textfile(const char *filename, size_t letters)
{
	int _open, _read;
	char *ptr = NULL;

	if (filename == NULL)
	{
		dprintf(STDERR_FILENO, "Error: Can't open file %s\n", filename);
		exit(1);
	}
	ptr = malloc(sizeof(char) * letters);
	if (ptr == NULL)
	{
		dprintf(STDERR_FILENO, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}
	_open = open(filename, O_RDONLY);
	if (_open == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't open file %s\n", filename);
		free(ptr);
		exit(EXIT_FAILURE);
	}
	_read = read(_open, ptr, letters);
	if (_read == -1 || _read == 0)
	{
		dprintf(2, "Error: Can't open file %s\n", filename);
		exit(EXIT_FAILURE);
	}
	close(_open);
	return (ptr);
}

/**
 * handle - tokenize arguments and call functions.
 * @ptr: file name.
 * Return: characters prints.
 */

int handle(char *ptr)
{
	char **tokens = NULL, **arg = NULL;
	stack_t *head = NULL;
	unsigned int line_number = 0, i = 0;

	tokens = tock_arg(ptr);
	while (tokens[i] != NULL)
	{
		arg = tock_2(tokens[i]);
		line_number = i + 1;
		if (arg != NULL)
		{
			if (arg[1] != NULL)
				value = atoi(arg[1]);
			funtions(arg[0], &head, line_number);
		}
		free_dpointer(arg);
		i++;
	}
	free_dpointer(tokens);
	free(ptr);
	return (0);
}
/**
 * free_dpointer - free pointer.
 * @pointer: Pointer.
 * Return: characters prints.
 */

int free_dpointer(char **pointer)
{
	int i = 0;

	while (pointer[i] != NULL)
	{
		free(pointer[i]);
		i++;
	}
	free(pointer);
	return (0);
}
