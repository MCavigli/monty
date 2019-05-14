#include "monty.h"

/**
 * op_push - function that push an element to the stack
 * @stack: a pointer to the head of a linked list
 * @line_number: the line number
 *
 * Return: nothing
 */

stack_t *op_push(stack_t **stack, unsigned int line_number)
{
	stack_t *new_node;
	(void)line_number;

	if (!stack)
		return (NULL);

	new_node = malloc(sizeof(stack_t));
	if (!new_node)
	{
		return (NULL);
	}
	new_node->n = node_data;
	new_node->next = NULL;
	new_node->prev = NULL;

	if (*stack)
	{
		new_node->next = *stack;

		(*stack)->prev = new_node;

		*stack = new_node;
	}
	else
	{
		*stack = new_node;
	}
	return (new_node);
}

/**
 * op_pall - function that prints out all the elements of a linked list
 * @stack: a pointer to the head of a linked list
 * @line_number: the line number
 *
 * Return: nothing
 */

stack_t *op_pall(stack_t **stack, unsigned int line_number)
{
	(void)line_number;

	while (*stack)
	{
		printf("%d\n", (*stack)->n);
		*stack = (*stack)->next;
	}
	return (*stack);
}
