#include "monty.h"

/**
  * release_stacks - frees elements in the stack
  *
  * Return: Nothing on success
  */
void release_stacks(void)
{
	stack_t *temp = NULL;

	if (head)
	{
		temp = head;

		while (temp)
		{
			head = head->next;
			free(temp);
			temp = head;
		}
	}
}
