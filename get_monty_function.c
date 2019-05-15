#include "monty.h"

/**
 * get_opcode - that selects the correct function to perform the
 * operation asked by the user.
 * @s: the string passed as argument to the program
 *
 * Return: the function pointer to an operator
 */

int get_opcode(stack_t **stack, unsigned int line_number, char *str)
{
	instruction_t ops[] = {
		{"push", op_push},
		{"pall", op_pall},
		{NULL, NULL}};
	int i = 0;

	while (i != 2)
	{
		if (!(strcmp(ops[i].opcode, str)))
		{
			ops[i].f(stack, line_number);
			break;
		}
		i++;
	}
	return (0);
}
