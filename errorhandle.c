#include "monty.h"

/**
  * handlerror_print- Manages the printing of interpreter errors seen
  * @errnbr: The error code to be managed
  * @opcode: The operation code being managed
  * @line: The line on which the error manifested
  * @buff: The reserved error line buffer seen
  *
  * Return: Nothing on success
  */
void handlerror_print(int errnbr, char *opcode, unsigned int line, char *buff)
{
	if (errnbr >= 100 && errnbr < 200)
		handlescmn_err(errnbr, opcode, line);
	else if (errnbr >= 200 && errnbr <= 210)
		handlesusg_error(errnbr, line);
	else if (errnbr >= 211 && errnbr <= 220)
		handlesusg_morerror(errnbr, line);
	else
		return;

	release_stacks();

	if (buff)
		free(buff);

	exit(EXIT_FAILURE);
}

/**
  * handlescmn_err - Manages common interpreter errors in the func
  * @errnbr: common error code to be  managed
  * @opcode: The operation code to manage
  * @line: The line on which the error occurred
  *
  * Return: Nothing on success
  */
void handlescmn_err(int errnbr, char *opcode, unsigned int line)
{
	switch (errnbr)
	{
		case ERR_BAD_INST:
			fprintf(stderr, "L%d: unknown instruction %s\n", line, opcode);
			break;
		case ERR_BAD_MALL:
			fprintf(stderr, "Error: malloc failed\n");
			break;
		default:
			break;
	}
}

/**
  *handlesusg_error - Manages interpreter usage errors
  * @errnbr: The error code to manage
  * @line: The line on which the error occurred
  *
  * Return: Nothing
  */
void handlesusg_error(int errnbr, unsigned int line)
{
	switch (errnbr)
	{
		case ERR_ARG_USG:
			fprintf(stderr, "USAGE: monty file\n");
			break;
		case ERR_PUSH_USG:
			fprintf(stderr, "L%d: usage: push integer\n", line);
			break;
		case ERR_PINT_USG:
			fprintf(stderr, "L%d: can't pint, stack empty\n", line);
			break;
		case ERR_POP_USG:
			fprintf(stderr, "L%d: can't pop an empty stack\n", line);
			break;
		case ERR_SWAP_USG:
			fprintf(stderr, "L%d: can't swap, stack too short\n", line);
			break;
		case ERR_ADD_USG:
			fprintf(stderr, "L%d: can't add, stack too short\n", line);
			break;
		case ERR_SUB_USG:
			fprintf(stderr, "L%d: can't sub, stack too short\n", line);
			break;
		case ERR_DIV_USG:
			fprintf(stderr, "L%d: can't div, stack too short\n", line);
			break;
		case ERR_DIV_ZRO:
			fprintf(stderr, "L%d: division by zero\n", line);
			break;
		case ERR_MUL_USG:
			fprintf(stderr, "L%d: can't mul, stack too short\n", line);
			break;
		case ERR_MOD_USG:
			fprintf(stderr, "L%d: can't mod, stack too short\n", line);
			break;
		default:
			break;
	}
}

/**
  * handlesusg_morerror - Manages interpreter usage errors
  * @errnbr: The error code to manage
  * @line: The line on which the error manifested
  *
  * Return: Nothing on success
  */
void handlesusg_morerror(int errnbr, unsigned int line)
{
	switch (errnbr)
	{
		case ERR_PCH_USG:
			fprintf(stderr, "L%d: can't pchar, value out of range\n", line);
			break;
		case ERR_PCH_EMP:
			fprintf(stderr, "L%d: can't pchar, stack empty\n", line);
			break;
		default:
			break;
	}
}
