#include "monty.h"

void op_pall(const stack_t *h)
{
	while (h)
	{
		printf("%d\n", h->n);
		h = h->next;
	}
}
