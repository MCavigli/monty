#include "monty.h"

void op_swap(stack_t **stack, unsigned int line_number)
{
	stack_t *node1 = *stack;
	stack_t *node2 = (*stack)->next;
	stack_t *temp;
	stack_t *node3;

	if (*stack && (*stack)->next)
	{
		node3 = node2->next;
		temp = node1->prev;

		node1->next = node3;
		node1->prev = node2;

		node2->prev = temp;
		node2->next = node1;

		if(node3 != NULL)
		{
			node3->prev = node1;
		}
		*stack = node2;
	}

	else
	{
		dprintf(2, "L%u: can't swap, stack too short", line_number);
		exit(EXIT_FAILURE);
	}
}
