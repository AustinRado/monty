#include "monty.h"

/**
 * main - entry point.
 * @argc: Number of arguments
 * @argv: array of arguments
 * Return: EXIT_SUCCESS esle EXIT_FAILURE
 */

int main(int argc, char *argv[])
{
	(void)argv;
	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n", argv[0]);
		return (EXIT_FAILURE);
	}
	char *filename = argv[1];
	FILE *file = fopen(filename, "r");

	if (file == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", filename);
		return (EXIT_FAILURE);
	}
	execute(file);
	fsclose(file);

	return (EXIT_SUCCESS);
}
