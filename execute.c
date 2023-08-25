#include "monty.h"

#define MAX_BUFFER_SIZE 256


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
	char *opcode;
	unsigned int value;

	while (fgets(buffer, sizeof(buffer), file) != NULL)
	{
		buffer[strcspn(buffer, "\n")] = '\0';
		opcode = strtok(buffer, " ");

		if (opcode == NULL)
		{
			fprintf(stderr, "L%u: unknown instruction\n", line_number);
			exit(EXIT_FAILURE);
		}
		if (strcmp(opcode, "push") == 0)
		{
			char *value_str = strtok(NULL, " ");
			if (value_str == NULL)
			{
				fprintf(stderr, "L%u: usage: push integer\n", line_number);
				 exit(EXIT_FAILURE);
			}
			if (sscanf(value_str, "%u", &value) != 1)
			{
				fprintf(stderr, "L%u: invalid value for push\n", line_number);
				exit(EXIT_FAILURE);
			}
			push(&stack, value);
		}
		else if (strcmp(opcode, "pint") == 0)
		{
			pint(&stack, line_number);
		}
		else if(strcmp(opcode, "pop") == 0)
		{
			pop(&stack, line_number);
		}
		else if(strcmp(opcode, "swap") == 0)
		{
			swap(&stack, line_number);
		}
		else if (strcmp(opcode, "add") == 0)
		{
			add(&stack, line_number);
		}
		else if (strcmp(opcode, "nop") == 0)
		{
			nop(&stack, line_number);
		}
		else
		{
			fprintf(stderr, "L%u: unknown instruction %s\n", line_number, opcode);
			exit(EXIT_FAILURE);
		}
		line_number++;
	}
	memory_free(stack);
}
