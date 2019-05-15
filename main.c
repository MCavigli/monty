#include "monty.h"
glo_t glo;
/**
* main - reads a monty file and executes line by line
* @argc: argument counter
* @argv: argument vector
* Return: 0
*/

int main(int argc, char **argv)
{
	stack_t *head = NULL;
	glo.line_buff = NULL;
	glo.bigb = NULL;
	size_t line_buff_size = 0;
	unsigned int counter = 0;
	ssize_t lines;
	int check;
/*
	stack_t *head = NULL;
	char *line_buff = NULL;
	char **bigb = NULL;
	size_t line_buff_size = 0;
	FILE *fp;
	unsigned int counter = 0;
	ssize_t lines;
	int check;
*/
	argc_check(argc);
/*
	if (argc != 2)
	{
		dprintf("USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
*/

	glo.fp = fopen(argv[1], "r");
	open_check(argv);
/*
	if (fp == NULL)
	{
		printf("Error: Can't open file \n");
		exit(EXIT_FAILURE);
	}
*/
	lines = getline(&glo.line_buff, &line_buff_size, glo.fp);
	line_check(lines);
/*
	if (lines == -1)
	{
		free(line_buff);
		exit(0);
	}
*/
	while (lines >= 0)
	{
		bigb = NULL;
		counter++;
		glo.bigb = parse_line();
		if (glo.bigb[1] != NULL)
			glo.node_data = atoi(glo.bigb[1]);
		check = get_opcode(&head, counter);

		if (check == 0)
		{
/*
  op_check(check, counter, bigb, line_buff);
*/

			dprintf(2, "L%u: unknown instruction %s\n", counter, bigb[0]);
			free(glo.bigb);
			free(glo.line_buff);
			fclose(glo.fp);
			exit(EXIT_FAILURE);
		}



		lines = getline(&glo.line_buff, &line_buff_size, glo.fp);
	}
	free(glo.bigb);
	free(glo.line_buff);
	fclose(glo.fp);
	return (0);
}
