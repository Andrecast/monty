#include "monty.h"
/**
 * main - check the code for Holberton School students.
 * @ac: length array.
 * @av: double pointer strings
 * Return: Always 0.
 */
int main(int ac, char **av)
{
	size_t letters = 500;
	char *arguments = NULL;

	if (ac != 2)
	{
		printf("USAGE: monty file\n");
		exit(1);
	}
	arguments = read_textfile(av[1], letters);
	handle(arguments);
	return (0);
}
