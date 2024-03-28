#include "monty.h"

/**
  * checksargs_numbr - Checksarguments passed on interpreter in the prog
  * @argn: Number of args passed in the func
  *
  * Return: Nothing
  */
void checksargs_numbr(int argn)
{
	if (argn != MIN_ARGS)
		handlerror_print(ERR_ARG_USG, NULL, 0, NULL);
}

/**
  * verifaccess_entity - verifies if the user has permissions to read the file
  * @filename: The pathname of the file in the func
  *
  * Return: Nothing on success
  */
void verifaccess_entity(char *filename)
{
	if (access(filename, R_OK) == -1)
	{
		fprintf(stderr, "Error: Can't open file %s\n", filename);
		exit(EXIT_FAILURE);
	}
}

/**
  * checks_pushparmtr - Check the parameter of the push instruction
  * @param: The parameter to be verified in the func
  *
  * Return: 0 if is a valid param or errercode if is invalid
  */
int checks_pushparmtr(char *param)
{
	if (param == NULL || checks_char_is_dig(param) == 0)
		return (ERR_PUSH_USG);

	return (VALID_PARM);
}

/**
  * checks_char_is_dig - Check if all the characters in a string are digits
  * @s: The string to be evaluated in the func
  *
  * Return: 1 if all if all evaluated characters are digits or 0 if not seen
  */
int checks_char_is_dig(char *s)
{
	int status = 1;

	while (*s != '\0')
	{
		if (s[0] == 45)
		{
			++s;
			continue;
		}

		if (isdigit(*s) == 0)
		{
			status = 0;
			return (status);
		}

		++s;
	}

	return (status);
}
