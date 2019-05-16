#include "monty.h"

/**
 * sub_error - Error functionality for op_sub()
 * @c: line count
 * Return: nothing
 */
void sub_error(unsigned int c)
{
	dprintf(STDERR_FILENO, "L%u: can't sub, stack too short\n", c);
	exit(EXIT_FAILURE);
}
