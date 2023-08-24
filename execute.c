#include "monty.h"

#define MAX_BUFFER_SIZE 256

static instruction_t instructions[] = {
	{"push", push},
	{"pall", pall},
	{NULL, NULL}
};

/**
 * memory_free - free memory.
 * @curr: current stack.
 */

void memory_free(stack_t *curr)
{
	while (curr != NULL)
	{
		stack_t *temp = curr;

		curr = curr->next;

		free(temp);
	}
}

/**
 * exe_instruction - executes monty bytecode instructions.
 * @file: file pointer
 */

void exe_instruction(FILE *file)
{
	char buffer[MAX_BUFFER_SIZE];
	stack_t *stack = NULL;
	int line_number = 1;
	int found = 0;
	int i;
	char *opcode;

	while (fgets(buffer, sizeof(buffer), file) != NULL)
	{
		buffer[strcspn(buffer, "\n")] = '\0';
		opcode = strtok(buffer, " ");

		if (opcode == NULL)
		{
			fprintf(stderr, "L%u: unknown instruction\n", line_number);
			exit(EXIT_FAILURE);
		}

		for (i = 0; instructions[i].opcode != NULL; i++)
		{
			if (strcmp(opcode, instructions[i].opcode) == 0)
			{
				instructions[i].f(&stack, line_number);
				found = 1;
				break;
			}
		}

		if (!found)
		{
			fprintf(stderr, "L%u: unknown instruction %s\n", line_number, opcode);
			exit(EXIT_FAILURE);
		}
		line_number++;
	}
	memory_free(stack);
}
