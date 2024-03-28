#include "monty.h"

/**
 *topsub - Subtracts top element of the stack
 * from the second top element of the stack in the func
 * @stack: The head of the stack
 * @line: The line on which the error manifesteds
 *
 * Return: Nothing on success
 */
void topsub(stack_t **stack, unsigned int line)
{
	stack_t *temp = *stack;
	unsigned int a = 0, v = 0, length = 0;

	length = stacks_cont(*stack);

	if (length < 2)
		handlerror_print(ERR_SUB_USG, NULL, line, NULL);

	a = temp->n;
	v = temp->next->n;
	temp->next->n = v - a;
	*stack = temp->next;
	free(temp);
}
