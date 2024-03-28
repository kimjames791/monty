#include "monty.h"

/**
 * multop_sec - Multiplies the second top element of the stack
 * with the top element of the stack
 * @stack: The head of the stack in the func
 * @line_number: The line on which error manifests
 *
 * Return: Nothing on success
 */
void multop_sec(stack_t **stack, unsigned int line_number)
{
	stack_t *temp = *stack;
	unsigned int k = 0, b = 0, length = 0;

	length = stacks_cont(*stack);

	if (length < 2)
		handlerror_print(ERR_MUL_USG, NULL, line_number, NULL);

	k = temp->n;
	b = temp->next->n;
	temp->next->n = b * k;
	*stack = temp->next;
	free(temp);
}
