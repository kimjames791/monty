#include "monty.h"

/**
  * push - Adds a new node at the beginning of the stack
  * @stack: The head of the stack
  * @param: The value to adds on the stack
  *
  * Return: Nothing
  */
void push(stack_t **stack, unsigned int param)
{
	stack_t *new_node = NULL;

	new_node = malloc(sizeof(stack_t));
	if (new_node == NULL)
		handlerror_print(ERR_BAD_MALL, NULL, 0, NULL);

	new_node->n = param;
	if (*stack)
	{
		new_node->next = *stack;
		new_node->prev = (*stack)->prev;
		(*stack)->prev = new_node;
		*stack = new_node;
		return;
	}

	new_node->next = *stack;
	new_node->prev = NULL;
	*stack = new_node;
}

/**
  * pushque_add - Adds new node at the end of stack
  * @stack: The head of the stack
  * @parmtr: The value to be added on the stack in the func
  *
  * Return: Nothing on sucess
  */
void pushque_add(stack_t **stack, unsigned int parmtr)
{
	stack_t *current = NULL, *new_node = NULL;

	new_node = malloc(sizeof(stack_t));
	if (new_node == NULL)
		handlerror_print(ERR_BAD_MALL, NULL, 0, NULL);

	new_node->n = parmtr;
	if (*stack)
	{
		current = *stack;
		while (current->next != NULL)
			current = current->next;

		new_node->next = NULL;
		new_node->prev = current;
		current->next = new_node;
		return;
	}

	new_node->next = *stack;
	new_node->prev = NULL;
	*stack = new_node;
}
