#include "monty.h"

/**
 * computesrest - Computes rest of the division of the second top element
 * of the stack by the top element of the stack
 * @stack: The head of the stack in the func
 * @line: The line on which the errorwas manifested
 *
 * Return: Nothing on sucees
 */
void computesrest(stack_t **stack, unsigned int line)
{
	stack_t *temp = *stack;
	unsigned int k = 0, b = 0, length = 0;

	length = stacks_cont(*stack);

	if (length < 2)
		handlerror_print(ERR_MOD_USG, NULL, line, NULL);

	k = temp->n;

	if (k == 0)
		handlerror_print(ERR_DIV_ZRO, NULL, line, NULL);

	b = temp->next->n;
	temp->next->n = b % k;
	*stack = temp->next;
	free(temp);
}
