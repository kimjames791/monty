#include "monty.h"

/**
  * openfil_int - Opensthea file to interpret the commands within
  * @filename: The  opened
  *
  * Return: The file descriptor
  */
FILE *openfil_inter(char *filename)
{
	FILE *fd = NULL;

	verifaccess_entity(filename);

	fd = fopen(filename, "r");

	if (!fd)
	{
		fprintf(stderr, "Error: Can't open file %s\n", filename);
		exit(EXIT_FAILURE);
	}

	return (fd);
}
