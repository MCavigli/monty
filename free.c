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
