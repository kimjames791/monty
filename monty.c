#include "monty.h"
#include <stdio.h>

/**
  * main - The Monty Interpreter entry point/entry to my prog
  * @argn: The args number passed
  * @args: The args passed to the interpreter in prog
  *
  * Return: Always zero if success
  */
int main(int argn, char *args[])
{
	FILE *fd = NULL;
	size_t line_len = 0;
	unsigned int line_num = 1;
	int readed = 0, op_status = 0;
	char *filename = NULL, *op_code = NULL, *op_parmt = NULL, *buff = NULL;

	filename = args[1];
	checksargs_numbr(argn);
	fd = openfil_inter(filename);

	while ((readed = getline(&buff, &line_len, fd)) != -1)
	{
		op_code = strtok(buff, "\t\n ");
		if (op_code)
		{
			if (op_code[0] == '#')
			{
				++line_num;
				continue;
			}

			op_parmt = strtok(NULL, "\t\n ");
			op_status = execute_handled(op_code, op_parmt, line_num, op_status);

			if (op_status >= 100 && op_status < 300)
			{
				fclose(fd);
				handlerror_print(op_status, op_code, line_num, buff);
			}
		}

		++line_num;
	}

	release_stacks();
	free(buff);
	fclose(fd);
	return (0);
}
