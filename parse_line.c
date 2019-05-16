#include "monty.h"
glo_t glo;
/**
 * parse_line - tokenizes the line
 * Return: an array of strings that holds the line and an argument if necessary
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
/*
	glo.node_data = atoi(strtok(NULL, " \t"));
	return (token);
*/
/*
		next_token = strtok(NULL, " \t");
		while (next_token[i])
		{
			if (next_token[i] == '-')
			{
				i++;
				continue;
			}
			if (isdigit(next_token[i]))
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
*/

/*
	char **big_buff = malloc(10 * (sizeof(char *)));
	char *token;
	int i = 0;

	if (!big_buff)
	{
		dprintf(2, "Error: malloc failed\n");
		free(glo.line_buff);
		fclose(glo.fp);
		exit(EXIT_FAILURE);
	}

	while (glo.line_buff[i])
		i++;

	if (glo.line_buff[i - 1] == '\n')
		glo.line_buff[i - 1] = '\0';

	token = strtok(glo.line_buff, " \t");
	i = 0;
	while (token)
	{
		big_buff[i] = token;
		i++;
		token = strtok(NULL, " \t");
	}
	big_buff[i] = NULL;
	return (big_buff);
*/
}
