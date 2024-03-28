#include "monty.h"

/**
 *topadd - Adds top two elements of the stack
 * @stack: The head of the stack in the func
 * @line: The line on which the error manifested
 *
 * Return: Nothing on suceese
 */
void topadd(stack_t **stack, unsigned int line)
{
	stack_t *temp = *stack;
	unsigned int a = 0, v = 0, length = 0;

	length = stacks_cont(*stack);

	if (length < 2)
		handlerror_print(ERR_ADD_USG, NULL, line, NULL);

	a = temp->n;
	v = temp->next->n;
	temp->next->n = a + v;
	*stack = temp->next;
	free(temp);
}
