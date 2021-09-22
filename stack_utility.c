#include "monty.h"

/**
 * check_isdigit - checks string is only digit
 * @str: string input argument
 * Return: 0 is only digit or 1 not digit
 */

int check_isdigit(char *str)
{
int c;
for (c = 0; str[c]; c++)
{
if (str[c] == '-' && c == 0)
continue;
if (isdigit(str[c]) == 0)
return (1);
}
return (0);
}

/**
 * set_queue - sets the format of the data to a queue (FIFO)
 * @stack: double pointer to the top of the stack
 * @line: script line number
 */
void set_queue(stack_t **stack, unsigned int line)
{
(void) stack;
(void) line;
var.len_queue = QUEUE;
}

/**
 * set_stack - sets the format of the data to a stack (LIFO)
 * @stack: double pointer to the top of the stack
 * @line: script line number
 */
void set_stack(stack_t **stack, unsigned int line)
{
(void) stack;
(void) line;
var.len_queue = STACK;
}
