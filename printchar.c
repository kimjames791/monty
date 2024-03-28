#include "monty.h"

/**
  * printchar - Prints the char top of the stack,
  * followed by a new line
  * @stack: The head of the stack
  * @line: The line on which the error was manifested
  *
  * Return: Nothing on success
  */
void printchar(stack_t **stack, unsigned int line)
{
	if (*stack == NULL)
		handlerror_print(ERR_PCH_EMP, NULL, line, NULL);

	if ((*stack)->n >= 0 && (*stack)->n <= 127)
		printf("%c\n", (*stack)->n);
	else
		handlerror_print(ERR_PCH_USG, NULL, line, NULL);
}
