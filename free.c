#include "monty.h"
glo_t glo;
/**
 * free_buff - frees buffers from main
 * Return: nothing
 */
void free_buff()
{
	free(glo.bigb);
	free(glo.line_buff);
	fclose(glo.fp);
}

/**
 * free_stack - frees a list
 * @head: pointer to head of the list
 * Return: nothing
 */

void free_stack(stack_t *head)
{
	stack *temp;

	while (head)
	{
		temp = head->next;
		free(head);
		head = temp;
	}
}
