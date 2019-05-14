#include "monty.h"

/**
 * get_opcode - that selects the correct function to perform the
 * operation asked by the user.
 * @s: the string passed as argument to the program
 *
 * Return: the function pointer to an operator
 */

void (*get_opcode(char *line))(stack_t **stack, unsigned int line_number)
{
	instruction_t ops[] = {
		{"push", op_push},
		{"pall", op_pall},
		{NULL, NULL}};
	int i = 0;

	while (i != 7)
	{
		if (!(strcmp(ops[i].opcode, line)))
		{
			return (ops[i].f);
		}
		i++;
	}
	return (NULL);
}
