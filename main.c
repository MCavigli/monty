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
	unsigned int counter = 0;
	ssize_t lines;
	int check;

	if (argc != 2)
	{
		printf("USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	fp = fopen(argv[1], "r");
	if (fp == NULL)
	{
		printf("Error: Can't open file \n");
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
		printf("BIGB[0]: %s\n", bigb[0]);
		if (bigb[1] != NULL)
		{
			node_data = atoi(bigb[1]);
			printf("BIGB[1]: %s\n", bigb[1]);
		}
		check = get_opcode(&head, counter, bigb[0]);
		if (check == 0)
		{
			printf("L: unknown instruction\n");
			exit(EXIT_FAILURE);
		}


		lines = getline(&line_buff, &line_buff_size, fp);
	}
	free(bigb);
	free(line_buff);
	fclose(fp);
	return (0);
}
