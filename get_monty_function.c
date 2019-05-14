#include "monty.h"

/**
 * get_opcode - that selects the correct function to perform the
 * operation asked by the user
 * @s: the string passed as argument to the program
 *
 * Return: the function pointer to an operator
 */

int (*get_opcode(char *str, int line_number))
{
	op_t ops[] = {
		{"push", op_push},
		{"pall", op_pall},
		{"pint", op_pint},
		{"pop", op_pop},
		{"swap", op_swap},
		{"add", op_add},
		{"nop", op_nop},
		{NULL, NULL}};
	int i = 0;

	while (i != 7)
	{
		if (!(strcmp(ops[i].op, s)))
		{
			return (ops[i].f);
		}
		i++;
	}
	return (NULL);
}
