#include "monty.h"

/**
 * topremv - Remove top element of the stack
 * @stack: The head of the stack in the func
 * @line: The line on which the error occurred
 *
 * Return: Nothing on sucees
 */
void topremv(stack_t **stack, unsigned int line)
{
	stack_t *current = *stack, *temp = NULL;

	if (*stack == NULL)
		handlerror_print(ERR_POP_USG, NULL, line, NULL);

	temp = current;
	if (current->next)
	{
		current = current->next;
		current->prev = temp->prev;
		*stack = current;
	}
	else
	{
		*stack = NULL;
	}

	free(temp);
}
