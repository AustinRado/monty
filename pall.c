#include "monty.h"

/**
 *pall - prints elements of the stack
 *@stack: pointer to the stack
 *@line_number: unused variable
 */

void pall(stack_t **stack, unsigned int line_number)
{
	stack_t *current = *stack;

	(void)line_number;

	while (current != NULL)

	{
		printf("%d\n", current->n);
		current = current->next;
	}
}
