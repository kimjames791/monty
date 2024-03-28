#include "monty.h"

/**
  * execute_handled - Manages operation to be executed by interpreter
  * @op_code: The operation code tobe  managed
  * @op_parmt: The parameter passed
  * @line: The line on which the error seen
  * @k: The method to be used by the interpreter in the func
  *
  * Return: 0 if the operation executed or errercode if is invalid
  */
int execute_handled(char *op_code, char *op_parmt, unsigned int line, int k)
{
	int status_op = 0;
	void (*oprt)(stack_t **, unsigned int);

	if (strcmp(op_code, "stack") == 0)
		return (METH_STACK);
	else if (strcmp(op_code, "queue") == 0)
		return (METH_QUEUE);

	oprt = pick_func(op_code);
	if (oprt)
	{
		if (strcmp(op_code, "push") == 0)
		{
			status_op = checks_pushparmtr(op_parmt);
			if (status_op == ERR_PUSH_USG)
				return (ERR_PUSH_USG);

			if (k != 0 && k == METH_QUEUE)
				oprt = pick_func("push_queue");

			oprt(&head, atoi(op_parmt));
		}
		else
		{
			oprt(&head, line);
		}

		return (k);
	}

	return (ERR_BAD_INST);
}
