#include "monty.h"
glo_t glo;

/**
 * get_opcode - that selects the correct function to perform the
 * operation asked by the user.
 * @s: the string passed as argument to the program
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
		{NULL, NULL}};
	int i = 0;

	while (i != 5)
	{
		if (!(strcmp(ops[i].opcode, glo.bigb)))
		{
			ops[i].f(stack, line_number);
			break;
		}
		i++;
	}
	return (1);
}