#include "monty.h"

/**
  * print_s - Prints the string starting at the top of the stack,
  * followed by a new line
  * @stack: The head of the stack
  * @line: The line on which the error occurred
  *
  * Return: Nothing on sucess
  */
void print_s(stack_t **stack, unsigned int line)
{
	stack_t *curr = *stack;
	(void) line;

	while (curr != NULL)
	{
		if (curr->n == 0 || curr->n < 0 || curr->n > 127)
			break;

		printf("%c", curr->n);
		curr = curr->next;
	}

	printf("\n");
}
