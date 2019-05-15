#include "monty.h"
glo_t glo;
/**
 * parse_line - tokenizes the line
 * @line: the line
 * Return: an array of strings that holds the line and an argument if necessary
 */

char **parse_line()
{
	char **big_buff = malloc(10 * (sizeof(char *)));
	char *token;
	int i = 0;

	while (glo.line[i])
		i++;

	if (glo.line[i - 1] == '\n')
		glo.line[i - 1] = '\0';

	token = strtok(glo.line, " \t");
	i = 0;
	while (token)
	{
		big_buff[i] = token;
		i++;
		token = strtok(NULL, " \t");
	}
	big_buff[i] = NULL;
	return (big_buff);
}
