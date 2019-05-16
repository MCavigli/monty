#include "monty.h"
glo_t glo;
/**
 * parse_line - tokenizes the line
 * @c: line number
 * Return: a token that holds the correct command
 */
char *parse_line(unsigned int c)
{
	char *token = NULL, *next_token = NULL;
	int i = 0;

	while (glo.line_buff[i])
		i++;
	if (i > 0 && glo.line_buff[i - 1] == '\n')
		glo.line_buff[i - 1] = '\0';
	i = 0;
	token = strtok(glo.line_buff, " \t");
	if (token == NULL)
		return (NULL);
	if (strcmp(token, "push") == 0)
	{
		next_token = strtok(NULL, " \t");
		if (next_token == NULL)
			integer_error(c);
		while (next_token[i])
		{
			if (i == 0 && next_token[i] == '-')
			{
				i++;
				continue;
			}
			if (next_token[i] >= 48 && next_token[i] <= 57)
			{
				i++;
				continue;
			}
			else
				integer_error(c);
		}
		glo.node_data = atoi(next_token);
	}
	return (token);
}

/**
 * integer_error - function that prints an integer error and exits
 * @c: line count
 * Return: nothing
 */
void integer_error(unsigned int c)
{
	dprintf(STDERR_FILENO, "L%u: usage: push integer\n", c);
	exit(EXIT_FAILURE);

}

/**
 * pint_error - prints a pint error and exits
 * @c: line number
 * Return: nothing
 */
void pint_error(unsigned int c)
{
	dprintf(STDERR_FILENO, "L%u: can't pint, stack empty\n", c);
	exit(EXIT_FAILURE);
}

/**
 * pop_error - prints a pop error and exits
 * @c: line number
 * Return: nothing
 */
void pop_error(stack_t **stack, unsigned int c)
{
	dprintf(STDERR_FILENO, "L%u: can't pop an empty stack\n", c);
	/* free_buff(); */
	free_stack(*stack);
	exit(EXIT_FAILURE);
}

/**
 * add_error - prints an add error and exits
 * @c: line number
 * Return: nothing
 */
void add_error(unsigned int c)
{
	dprintf(STDERR_FILENO, "L%u: can't add, stack too short\n", c);
	exit(EXIT_FAILURE);
}
