#include "monty.h"

/**
 * instruct_mod - rest of the division of the second top by the top
 * @stack: pointer to the top node of stack
 * @line: the current file line number calling instruction
 */
void instruct_mod(stack_t **stack, unsigned int line)
{
int n;
if (var.len_stack < 2)
{
fprintf(stderr, "L%u: can't mod, stack too short\n", line);
exit(EXIT_FAILURE);
}
n = (*stack)->n;
instruct_pop(stack, line);
if (n == 0)
{
fprintf(stderr, "L%u: division by zero\n", line);
exit(EXIT_FAILURE);
}
(*stack)->n %= n;
}

/**
 * instruct_pchar - prints the char at the top of the stack
 * @stack: pointer to the top node of stack
 * @line: the current file line number calling instruction
 */
void instruct_pchar(stack_t **stack, unsigned int line)
{
int ch;
if (var.len_stack < 1)
{
fprintf(stderr, "L%u: can't pchar, stack empty\n", line);
exit(EXIT_FAILURE);
}
ch = (*stack)->n;
if (!isascii(ch))
{
fprintf(stderr, "L%u: can't pchar, value out of range\n", line);
exit(EXIT_FAILURE);
}
printf("%c\n", ch);
}

/**
 * instruct_pstr - prints the string starting at the top of the stack
 * @stack: pointer to the top node of stack
 * @line: the current file line number calling instruction
 */
void instruct_pstr(stack_t **stack, unsigned int line __attribute__ ((unused)))
{
stack_t *tmp;
int ch;
tmp = *stack;
while (tmp != NULL)
{
ch = tmp->n;
if (!isascii(ch) || ch == 0)
break;
putchar(ch);
tmp = tmp->next;
if (tmp == *stack)
break;
}
putchar('\n');
}

/**
 * instruct_rotl - rotl rotates the stack to the top
 * @stack: pointer to the top node of stack
 * @line: the current file line number calling instruction
 */
void instruct_rotl(stack_t **stack, unsigned int line __attribute__ ((unused)))
{
if (*stack)
*stack = (*stack)->next;
}

/**
 * instruct_rotr - rotr rotates the stack to the bottom
 * @stack: pointer to the top node of stack
 * @line: the current file line number calling instruction
 */
void instruct_rotr(stack_t **stack, unsigned int line __attribute__ ((unused)))
{
if (*stack)
*stack = (*stack)->prev;
}
