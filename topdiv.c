#include "monty.h"

/**
 * topdiv - Divides second top element by the top element of the stack
 * @stack: The head of the stack
 * @line: The line on which the error manifested
 *
 * Return: Nothing on success
 */
void topdiv(stack_t **stack, unsigned int line)
{
	stack_t *temp = *stack;
	unsigned int a = 0, b = 0, length = 0;

	length = stacks_cont(*stack);

	if (length < 2)
		handlerror_print(ERR_DIV_USG, NULL, line, NULL);

	a = temp->n;

	if (a == 0)
		handlerror_print(ERR_DIV_ZRO, NULL, line, NULL);

	b = temp->next->n;
	temp->next->n = b / a;
	*stack = temp->next;
	free(temp);
}
