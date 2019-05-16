#include "monty.h"

/**
 * op_mod - moduluses the first 2 nodes
 * @stack: a pointer to the head of a linked list
 * @line_number: the line number
 *
 * Return: nothing
 */

void op_mod(stack_t **stack, unsigned int line_number)
{
	stack_t *current = *stack;
	stack_t *second_node;

	if (!current || !current->next)
		mod_error(line_number);

	if (current->n == 0)
	{
		dprintf(STDERR_FILENO, "L%u: division by zero\n", line_number);
		exit(EXIT_FAILURE);
	}
	second_node = current->next;
	second_node->n = second_node->n % current->n;
	op_pop(stack, line_number);
}
