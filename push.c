#include "monty.h"

/**
 * is_digit - checks if string is only digits
 * @arg: input string
 *
 * Return: 0 if only digits, else 1
 */
static int is_digit(char *arg)
{
	int i;

	for (i = 0; arg[i] != '\0'; i++)
	{
		if (arg[i] == '-' && i == 0)
			continue;
		if (isdigit(arg[i]) == 0)
			return (1);
	}
	return (0);
}

/**
 * m_push - push an integer onto the stack
 * @stack: double pointer to the beginning of the stack
 * @line_number: script line number
 *
 * Return: void
 */
void m_push(stack_t **stack, unsigned int line_number)
{
	char *input;
	int i;

	input = strtok(NULL, "\n\t\r ");

	if (input == NULL || is_digit(input))
	{
		dprintf(STDOUT_FILENO,
			"L%u: usage: push integer\n",
			line_number);
		exit(EXIT_FAILURE);
	}

	i = atoi(input);
	if (!add_node(stack, i))
	{
		dprintf(STDOUT_FILENO, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}
	var.stack_len++;
}
