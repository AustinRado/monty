#include "monty.h"

/**
 * sub - Subtracts the top element of the stack from the second top element.
 * @stack: Pointer to the top of the stack.
 * @line_number: Line number of the instruction.
 */

void sub(stack_t **stack, unsigned int line_number)
{
	int result;
	stack_t *temp;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%u: can't sub, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	result = (*stack)->next->n - (*stack)->n;

	temp = *stack;
	*stack = (*stack)->next;
	if (*stack != NULL)
	{
		(*stack)->prev = NULL;
	}

	free(temp);
	(*stack)->n = result;
}
