#include "monty.h"

/**
 * prit - Prints all the values on the stack,
 * starting from the top of the stack.
 * @stack: The head of the stack
 * @line: The line on which the error occurred
 *
 * Return: Nothing
 */
void prit(stack_t **stack, unsigned int line)
{
	stack_t *current = NULL;
	(void) line;

	if (*stack)
	{
		current = *stack;
		while (current != NULL)
		{
			printf("%d\n", current->n);
			current = current->next;
		}
	}
}
