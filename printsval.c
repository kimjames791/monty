#include "monty.h"

/**
 * printsval - Prints value at top of the stack,
 * followed by a new line.
 * @stack: The head of the stack
 * @line: The line on which error was manifested
 *
 * Return: Nothing on success
 */
void printsval(stack_t **stack, unsigned int line)
{
	if (*stack == NULL)
		handlerror_print(ERR_PINT_USG, NULL, line, NULL);

	printf("%d\n", (*stack)->n);
}
