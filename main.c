#include "monty.h"

/**
 * main - entry point.
 * @argc: Number of arguments
 * @argv: array of arguments
 * Return: EXIT_SUCCESS esle EXIT_FAILURE
 */

int main(int argc, char *argv[])
{
	char *filename = argv[1];
	FILE *file = fopen(filename, "r");

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		return (EXIT_FAILURE);
	}

	if (file == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", filename);
		return (EXIT_FAILURE);
	}

	exe_instruction(file);
	fclose(file);

	return (EXIT_SUCCESS);
}
