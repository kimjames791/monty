#include "monty.h"

/**
  * rotates - Rotates the stack to the bottom
  * @stack: The head of the stack
  * @line_number: The line on which the error occurred
  *
  * Return: Nothing
  */
void rotate(stack_t **stack, unsigned int line)
{
	stack_t *last = NULL;
	(void) line;

	if (*stack && (*stack)->next)
	{
		last = *stack;

		while (last->next != NULL)
			last = last->next;

		last->prev->next = NULL;
		last->next = *stack;
		*stack = last;
	}
}
