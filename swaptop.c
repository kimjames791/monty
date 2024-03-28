#include "monty.h"

/**
 * swaptop - Swaps the top two elements of the stack
 * @stack: The head of the stack
 * @line: The line on which the error manifested
 *
 * Return: Nothing on sucesse
 */
void swaptop(stack_t **stack, unsigned int line)
{
	unsigned int length = 0, temp = 0;

	length = stacks_cont(*stack);

	if (length < 2)
		handlerror_print(ERR_SWAP_USG, NULL, line, NULL);

	if (*stack)
	{
		temp = (*stack)->n;
		(*stack)->n = (*stack)->next->n;
		(*stack)->next->n = temp;
	}
}
