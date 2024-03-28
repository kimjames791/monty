#include "monty.h"

/**
  * pick_func - Select the function that relates to the Monty instruction
  * @s: The instruction to be executed
  *
  * Return: A pointer to the function to be executed or
  * NULL if the function don't exists
  */
void (*pick_func(char *s))(stack_t **, unsigned int)
{
	instruction_t insts[] = {
		{ "push", push },
		{ "pushque_add", pushque_add },
		{ "prit", prit },
		{ "printsval", printsval },
		{ "topremv",topremv },
		{ "swaptop", swaptop },
		{ "topadd", topadd },
		{ "nop", nop },
		{ "topsub", topsub },
		{ "topdiv", topdiv },
		{ "multop_sec", multop_sec },
		{ "computesrest", computesrest },
		{"printchar", printchar },
		{ "print_s", print_s },
		{ "rotate", rotate },
		{ NULL, NULL }
	};
	int i = 0;

	while (insts[i].opcode)
	{
		if (strcmp(s, insts[i].opcode) == 0)
			return (insts[i].f);

		++i;
	}

	return (NULL);
}
