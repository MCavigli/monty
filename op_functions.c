#include "monty.h"

/**
 *
 *
 *
 *
 */

void op_push()

/**
 * op_pall - function that prints out all the elements of a linked list
 * @h: a pointer to the head of a linked list
 *
 * Return: nothing
 */

void op_pall(stack_t **stack, unsigned int line_number)
{
	(void)line_number;

	while (*stack)
	{
		printf("%d\n", (*stack)->n);
		*stack = (*stack)->next;
	}
}
