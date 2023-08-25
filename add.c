#include "monty.h"

/**
 * add - Adds the top two elements of the stack.
 * @stack: Pointer to the top of the stack.
 * @line_number: Line number of the instruction.
 */
void add(stack_t **stack, unsigned int line_number)
{
	int sum;
	stack_t *temp;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		 fprintf(stderr, "L%u: can't add, stack too short\n", line_number);
		 exit(EXIT_FAILURE);
	}

	sum = (*stack)->n + (*stack)->next->n;
	
	temp = *stack;
	*stack = (*stack)->next;
	if (*stack != NULL)
	{
		(*stack)->prev = NULL;
	}
	free(temp);

	(*stack)->n = sum;
}
