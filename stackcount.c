#include "monty.h"

/**
  * stacks_cont - Counts number of elements in the stack
  * @stack: The stack to be counted
  *
  * Return: all Number of elements in the stack
  */
unsigned int stacks_cont(stack_t *stack)
{
	stack_t *current = stack;
	unsigned int lenght = 0;

	while (current != NULL)
	{
		++lenght;
		current = current->next;
	}

	return (lenght);
}
