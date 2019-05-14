#include "monty.h"

/**
* main - reads a monty file and executes line by line
* @argc: argument counter
* @argv: argument vector
* Return: 0
*/

int main(int argc, char **argv)
{
	stack_t *head = NULL;
	char *line_buff = NULL;
	char **bigb = NULL;
	size_t line_buff_size = 0;
	FILE *fp;
	int counter = 0;
	ssize_t lines;
	void (*func)(stack_t **stack, unsigned int line_number);

	if (argc != 2)
	{
		fprintf("USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	fp = fopen(argv[1], "r");
	if (fp == NULL)
	{
		fprintf("Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}
	lines = getline(&line_buff, &line_buff_size, fp);
	if (lines == -1)
	{
		free(line_buff);
		exit(0);
	}
	while (lines >= 0)
	{
		bigb = NULL, line_buff = NULL;
		counter++;
		bigb = parse_line(line_buff);
		if (bigb[1] != NULL)
			node_data = (int)bigb[1];
		func = get_opcode(bigb[0]);
		if (func == NULL)
		{
			fprintf("L%d: unknown instruction %s\n", lines, bigb[0]);
			exit(EXIT_FAILURE);
		}
		(func)(&head, counter);

		lines = getline(&line_buff, &line_buff_size, fp);
	}
	free(bigb);
	free(line_buff);
	fclose(fp);
	return (0);
}
