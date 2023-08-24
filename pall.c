#include "monty.h"
/**
 * f_pall - prints the stack
 * @head: input stack head
 * @counter: Head counter
*/
void f_pall(stack_t **head, unsigned int counter)
{
	stack_t *a;
	(void)counter;

	a = *head;
	if (a == NULL)
		return;
	while (a)
	{
		printf("%d\n", a->n);
		a = a->next;
	}
}
