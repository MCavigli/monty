#include "monty.h"
glo_t glo;
/**
 * parse_line - tokenizes the line
 * @c: line number
 * Return: a token that holds the correct command
 */
char *parse_line(int c)
{
	char *token = NULL;
	char *next_token = NULL;
	int i = 0;

	while (glo.line_buff[i])
		i++;
	if (glo.line_buff[i - 1] == '\n')
		glo.line_buff[i - 1] = '\0';
	i = 0;
	token = strtok(glo.line_buff, " \t");
	if (strcmp(token, "push") == 0)
	{
		next_token = strtok(NULL, " \t");
		if (next_token == NULL)
		{
			dprintf(2, "L%i: usage: push integer\n", c);
			exit(EXIT_FAILURE);
		}
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
			{
				dprintf(2, "L%i: usage: push integer\n", c);
				exit(EXIT_FAILURE);
			}
		}
		glo.node_data = atoi(next_token);
	}
	return (token);
}
