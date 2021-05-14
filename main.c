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

	if (ac != 2)
	{
		dprintf(2, "USAGE: monty file\n");
		exit(1);
	}
	read_textfile(av[1], buff);
	return (0);
}
