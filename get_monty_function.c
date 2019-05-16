#include "monty.h"
glo_t glo;

/**
 * get_opcode - that selects the correct function to perform the
 * operation asked by the user.
 * @stack: a pointer to the head of a linked list
 * @line_number: the line number
 *
 * Return: the function pointer to an operator
 */

int get_opcode(stack_t **stack, unsigned int line_number)
{
	instruction_t ops[] = {
		{"push", op_push},
		{"pall", op_pall},
		{"pint", op_pint},
		{"pop", op_pop},
		{"add", op_add},
		{"swap", op_swap},
		{"nop", op_nop},
		{"sub", op_sub},
		{"div", op_div},
		{"mul", op_mul},
		{"mod", op_mod,},
		{"pchar", op_pchar},
		{"pstr", op_pstr},
		{"rotl", op_rotl},
		{NULL, NULL}};
	int i = 0;

	while (i != 14)
	{
		if (!(strcmp(ops[i].opcode, glo.bigb)))
		{
			ops[i].f(stack, line_number);
			break;
		}
		i++;
	}
	if (i == 14)
		return (0);
	return (1);
}
