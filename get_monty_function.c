#include "monty.h"

/**
 * get_opcode - that selects the correct function to perform the
 * operation asked by the user
 * @s: the string passed as argument to the program
 *
 * Return: the function pointer to an operator
 */

void (*get_opcode(char *line))(stack_t **stack, unsigned int line_number)
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
		if (!(strcmp(ops[i].op, line)))
		{
			return (ops[i].f);
		}
		i++;
	}
	return (NULL);
}
