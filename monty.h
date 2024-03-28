#ifndef _MONTY_
#define _MONTY_

/* Constants */
#define SUCSS_OP		0
#define VALID_PARM		0
#define MIN_ARGS		2
#define METH_STACK		300
#define METH_QUEUE		301

/* Common Errors */
#define ERR_BAD_INST	100
#define ERR_BAD_MALL	101
#define ERR_INVLD_PARM	102

/* Usage Errors */
#define ERR_ARG_USG		200
#define ERR_PUSH_USG	201
#define ERR_PINT_USG	202
#define ERR_POP_USG		203
#define ERR_SWAP_USG	204
#define ERR_ADD_USG		205
#define ERR_SUB_USG		206
#define ERR_DIV_USG		207
#define ERR_DIV_ZRO		208
#define ERR_MUL_USG		209
#define ERR_MOD_USG		210
#define ERR_PCH_USG		211
#define ERR_PCH_EMP		212

#include <ctype.h>
#include <fcntl.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>

/**
 * struct stack - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue) in the prog
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structures.
 * for stack, queues, LIFO, FIFO Holberton project
 */
typedef struct stack
{
	int n;
	struct stack *prev;
	struct stack *next;
} stack_t;

/**
 * struct instructions - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO Holberton project
 */
typedef struct instructions
{
	char *opcode;
	void (*f)(stack_t **stack, unsigned int line);
} instruction_t;

extern stack_t *head;

void checksargs_numbr(int argn);
void verifaccess_entity(char *filename);
int checks_pushparmtr(char *param);
int checks_char_is_dig(char *s);
void multop_sec(stack_t **stack, unsigned int line_number);
void handlerror_print(int errnbr, char *opcode, unsigned int line, char *buff);
void handlescmn_err(int errnbr, char *opcode, unsigned int line);
void handlesusg_error(int errnbr, unsigned int line);
void handlesusg_morerror(int errnbr, unsigned int line);
void topremv(stack_t **stack, unsigned int line);
void pushque_add(stack_t **stack, unsigned int parmtr);
void computesrest(stack_t **stack, unsigned int line);
void printchar(stack_t **stack, unsigned int line);
void printsval(stack_t **stack, unsigned int line);
void swaptop(stack_t **stack, unsigned int line);
void topdiv(stack_t **stack, unsigned int line);
void topadd(stack_t **stack, unsigned int line);
void topsub(stack_t **stack, unsigned int line);
unsigned int stacks_cont(stack_t *stack);
void release_stacks(void);
int execute_handled(char *op_code, char *op_parmt, unsigned int line, int k);FILE *openfil_inter(char *filename);
void prit(stack_t **stack, unsigned int line);
void push(stack_t **stack, unsigned int param);
void print_s(stack_t **stack, unsigned int line);
void (*pick_func(char *s))(stack_t **, unsigned int);
void rotate(stack_t **stack, unsigned int line);
void nop(stack_t **stack, unsigned int line);
int main(int argn, char *args[]);


#endif
